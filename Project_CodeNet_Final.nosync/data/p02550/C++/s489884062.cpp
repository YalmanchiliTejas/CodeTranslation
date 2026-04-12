//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod = 998244353;
long double PI = acosl(-1);
const ll infl = 1e18;
const int inf = 2e9;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

ll nxt[nmax];
ll n, x, m;
bool vis[nmax];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>x>>m;
    for(ll i=0; i<m; i++){
        nxt[i] = (1LL*i*i)%m;
    }

    ll ans = 0;
    while(n--){
        if(vis[x]){
            n++;
//            cout<<"watff "<<endl;
            int luplen = 1;
            ll lupsam = x;
            int x1 = nxt[x];
            while(x1!=x){
                lupsam += x1, luplen += 1;
                x1 = nxt[x1];
//                cout<<"atka" <<endl;
            }
            ll taken = n / luplen;
            n %= luplen;
            ans += taken * lupsam;
            break;
        }
        ans += x;
        vis[x] = true;
        x = nxt[x];
//        cout<<"x = "<<x<<endl;
    }
//    cout<<n<<endl;
    for(int i=0; i<n; i++){
        ans += x;
        x = nxt[x];
//        cout<<"mane ki "<<endl;
//        cout<<n<<endl;
    }
    cout<<ans<<endl;


}
/*
*/
