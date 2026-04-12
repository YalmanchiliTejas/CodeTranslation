//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define int long long
#define ll long long
#define str string
#define db double
#define ac() cout<<"Yes"<<endl;
#define wa() cout<<"No"<<endl;
#define ddd cout<<"---debug---"<<endl;
#define ff(a,b) for(signed (a)=1;(a)<=(b);(a)++)
#define fff(a,b) for(signed (a)=0;(a)<(b);(a)++)
#define re readdd()
#define pr(a) printtt(a)
#define pee puts("");
#define eee putchar(' ');
#define pss(a) push_back(a)
#define ps(a) push(a)
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}//
int ppow(int a,int b,int mod){a%=mod;//
int ans=1%mod;while(b){if(b&1)ans=(long long)ans*a%mod;
a=(long long)a*a%mod;b>>=1;}return ans;}
int readdd(){int x=0,f=1;char c=getchar();//
while(!isdigit(c)&&c!='-')c=getchar();
if(c=='-')f=-1,c=getchar();
while(isdigit(c))x=x*10+c-'0',c=getchar();
return f*x;}
void printtt(int x){if(x<0)putchar('-'),x=-x;
if(x>=10)printtt(x/10);putchar(x%10+'0');}
bool addd(int a,int b){return a>b;};
//
const int maxm=3e3+5;
const int mod=998244353;
int d[maxm];
int a[maxm];
signed main(){
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s>a[i]){
            ans=(ans+d[s-a[i]]*(n-i+1)%mod)%mod;
        }else if(s==a[i]){
            ans=(ans+i*(n-i+1)%mod)%mod;
        }
        for(int j=s;j>=a[i];j--){
            d[j]=(d[j]+d[j-a[i]])%mod;
        }
        d[a[i]]=(d[a[i]]+i)%mod;
    }
    cout<<ans<<endl;
    return 0;
}

