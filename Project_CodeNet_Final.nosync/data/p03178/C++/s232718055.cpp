#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define PB push_back
#define MP make_pair
#define INF 1073741824
#define inf 1152921504606846976
#define pi 3.14159265358979323846
//#pragma comment(linker,"/STACK:10240000,10240000")
//mt19937 rand_(time(0));
const int N=3e5+7,M=2e6;
const long long mod=1e9+7;
inline int read(){int ret=0;char ch=getchar();bool f=1;for(;!isdigit(ch);ch=getchar()) f^=!(ch^'-');for(;isdigit(ch);ch=getchar()) ret=(ret<<1)+(ret<<3)+ch-48;return f?ret:-ret;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}//逆元
//int head[N],NEXT[M],ver[M],tot;void link(int u,int v){ver[++tot]=v;NEXT[tot]=head[u];head[u]=tot;}

char str[12000];
int num[12000];
ll dp[12000][120];
int k;
ll dfs(int pos,bool up,int sum){
    if(pos==1){
        if(sum%k==0) return 1;
        return 0;
    }
    if(dp[pos][sum]!=-1&&!up) return dp[pos][sum];
    ll res=0;
    for(int i=0;i<=(up?num[pos-1]:9);i++){
        if(up&&i==num[pos-1]){
            res+=dfs(pos-1,1,(sum+i)%k);
        }
        else {
            res+=dfs(pos-1,0,(sum+i)%k);
        }
//        cout<<res<<endl;
        res%=mod;
    }
//    cout<<pos<<' '<<sum<<' '<<res<<endl;
    if(!up) dp[pos][sum]=res;
    return res;
}
ll solve(){
    int len=strlen(str);
    int ant=0;
    for(int i=len-1;i>=0;i--){
        num[++ant]=str[i]-'0';
//        cout<<num[ant]<<' ';
    }
//    cout<<endl;
    return dfs(ant+1,1,0);
}
int main(){
    //freopen("1.txt","r",stdin);
    //ios::sync_with_stdio(false);
    scanf("%s",str);
    scanf("%d",&k);
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",(solve()-1+mod)%mod);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}



