#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define eps 1e-11
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef double db;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b){ return a*b/gcd(a,b); }
inline ll qsm(ll x,ll y){ ll res=1; while(y){if(y&1) res=res*x%mod;
x=x*x%mod; y>>=1;} return res; }
int n,m,k,rt;

int main(){
    scanf("%d%d",&n,&m);
    if(n==m) puts("Yes");
    else puts("No");
    return 0;
}
//
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                           O\  =  /O
//                        ____/`---'\____
//                      .'  \|     |//  `.
//                     /  \|||  :  |||//  \
//                    /  _||||| -:- |||||-  \
//                    |   | \  -  /// |   |
//                    | \_|  ''\---/''  |   |
//                    \  .-\__  `-`  ___/-. /
//                  ___`. .'  /--.--\  `. . __
//               ."" '<  `.___\_<|>_/___.'  >'"".
//              | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//              \  \ `-.   \_ __\ /__ _/   .-` /  /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//                     佛祖保佑      永无BUG
