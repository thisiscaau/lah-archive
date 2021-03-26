/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define log fuk
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 666013, MAXN = 2e5 + 5;
/* declaration */
ll n,m,opt,cnt;
struct edge{
    ll u,v,id;
};
struct state{
    bool open;
    edge e;
    ll p() const {
        if (open) return e.u;
        return e.v;
    }
    bool operator < (const state& other) const {
        if (p() != other.p())
            return p() < other.p();
        if (!open && other.open)
            return true;
        if (open && !other.open)
            return false;
        if (open){
            if (e.v != other.e.v)
                return e.v > other.e.v;
            return e.id < other.e.id;
        } 
        else{
            if (e.u != other.e.u)
                return e.u > other.e.u;
            return e.id > other.e.id;
        }
    }
};
ll type[MAXN];
vector<edge> g;
vector<ll> cut[MAXN];
vector<state> log;
/* workspace */
bool comp(edge a,edge b){
    if (a.u != b.u){
        return a.u < b.u;
    }
    return a.v < b.v;
}
stack<ii> st;
void dfs(ll u){
    // bipartite
    for (ll v : cut[u]){
        if (type[v] == 0){
            type[v] = 3 - type[u];
            dfs(v);
        }
    }
}
ll binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("AQUAPARK.inp","r",stdin);
    freopen("AQUAPARK.out","w",stdout);
    cin >> opt >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v; cin >> u >> v;
        if (u > v) swap(u,v);
        edge cur; cur.u = u; cur.v = v; cur.id = i;
        g.pb(cur);
        log.pb(state{true,cur});
        log.pb(state{false,cur});
    }
    /* 
    tldr : same type cannot cut each other
    */
    sort(g.begin(),g.end(),comp); // sort by order of corner
    for (int i = 1 ; i < m ; i++){
        if (g[i].u == g[i-1].u && g[i].v == g[i-1].v){
            cut[g[i].id].pb(g[i-1].id);
            cut[g[i-1].id].pb(g[i].id);
            cnt--;
        }
    }
    sort(log.begin(),log.end());
    for (auto cur : log){
        if (cur.open){
            st.push(mp(cur.e.u,cur.e.id));
        }
        else {
            ii tmp = mp(-1,-1);
            while (!st.empty() && st.top().fi > cur.e.u){
                tmp = st.top();
                st.pop();
                cut[cur.e.id].pb(tmp.se);
                cut[tmp.se].pb(cur.e.id);
            }
            if (!st.empty() && st.top() == mp(cur.e.u,cur.e.id)){
                st.pop();
            }
            if (tmp.fi != -1) st.push(tmp);
        }
    }
    for (int i = 1 ; i <= m ; i++){
        if (type[i] == 0){
            type[i] = 1;
            dfs(i);
            cnt++;
        }
    }
    if (opt == 1){
        for (auto e : g){
            cout << e.u << " " << e.v << " " << type[e.id] << endl;
        }
    }
    else {
        cout << binpow(2,cnt);
    }
}