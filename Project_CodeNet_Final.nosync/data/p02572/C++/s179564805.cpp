#include<iostream>
#include<cstdio>
#include<cstring>
#define pb emplace_back
#define LOCAL
  
using namespace std;
  
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+5;
typedef long long ll;
typedef pair<int,int> Pii;
const ll mod = 1e9+7;
 
template <typename T>inline void read(T& t){
    char c=getchar();t=0;
    int f=1;
    while(!isdigit(c)){
       if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c))t=t*10+c-48,c=getchar();
    t=f*t;
}
  
template <typename T,typename... Args> inline void read(T& t,Args&... args){
    read(t);read(args...);
}
 
ll a[maxn],sum[maxn];
  
int main(){
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    for(int i=n;i>=1;i--){
       sum[i]=(a[i]+sum[i+1])%mod;
    }
    ll ans=0;
    for(int i=n-1;i>=1;i--){
        ans=(ans+sum[i+1]*a[i]%mod)%mod;
    }
    printf("%lld\n",ans%mod);
    return 0;
}