#include<bits/stdc++.h>
using namespace std;
#define me(a,x) memset(a,x,sizeof(a))
#define sc scanf
#define pr printf
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+6;
const int mod=998244353;
template<typename T>int O(T s){cout<<s<<endl;return 0;}
template<typename T>void db(T *bg,T *ed){while(bg!=ed)cout<<*bg++<<' ';pr("\n");}
template<typename T>void db(vector<T>it){for(auto i:it)cout<<i<<' ';pr("\n");}
inline ll mul_64(ll x,ll y,ll c){return (x*y-(ll)((long double)x/c*y)*c+c)%c;}
inline ll ksm(ll a,ll b,ll c){ll ans=1;for(;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}
inline void exgcd(ll a,ll b,ll &x,ll &y){if(!b)x=1,y=0;else exgcd(b,a%b,y,x),y-=(a/b)*x;}
ll dp[3005];;
int n,s;
int a[N];
int main(){ 
    //IN
    cin>>n>>s;
    for(int i=0;i++<n;sc("%d",&a[i]));
    ll ans=0;
    for(int i=1;i<=n;i++){
        dp[0]++;
        for(int j=s;j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
            dp[j]%=mod;
        }
        ans+=dp[s];
        ans%=mod;
    }
    O(ans);
}