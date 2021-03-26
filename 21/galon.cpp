/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
// aurelion sol phu ho
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,e,pos,len,cur,dif;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("GALON.inp","r",stdin);
    freopen("GALON.out","w",stdout);
    cin >> n >> e;
    len = 1; cur = n-1;
    while (cur < e){
        cur += len; len++;
    }
    dif = -1;
    if (cur > e){
        len--;
        cur -= len;
        dif = e - cur;
    }
    ll can = len + 1;
    while (can != dif + 1 && can != 1){
        cout << can << " " << can-1 << "\n";
        can--;
    }
    if (dif > 0 ){
        cout << len + 2 << " " << can << "\n";
    }
    while (can != 1){
        cout << can << " " << can-1 << "\n";
        can--;
    }
    pos = len + 2;
    if (dif > 0) pos++;
    while (pos <= n){
        cout << pos << " " << 1 << "\n";
        pos ++;
    }
}