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
#define queue dumb
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll n,d;
ll res[MAXN];
set<pair<pair<ll,ll>,ll>> guest;
set<ll> waitlist;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("RAMEN.inp","r",stdin);
    freopen("RAMEN.out","w",stdout);
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++){
        ll t,pos; cin >> t >> pos;
        guest.insert(mp(mp(pos,t),i)); // prioritize pos
        waitlist.insert(t);
    }
    for (auto cur : guest){
        // first pos guest
        // tot = time + pos + d
        auto g = cur; ll pos = g.fi.fi, t = g.fi.se , i = g.se;
        auto it = waitlist.lower_bound(t-pos-d); // finding lower bound of t to have smaller
        // waiting time
        res[i] = *it + pos + d;
        waitlist.erase(*it);
    }
    for (int i = 1 ; i <= n ; i++){
        cout << res[i] << endl;
    }
}