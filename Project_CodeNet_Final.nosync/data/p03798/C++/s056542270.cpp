#include<bits/stdc++.h>
#define MEM(dp,i) memset(dp,i,sizeof(dp))
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int MX=2e5+9;
const ll inf=(1ll<<60);
const ll mod=1e9+7;
int n,a[MX];
string s;
bool check(ll x,char c,ll f,ll s){
    if(x&&c=='o'&&f!=s)return 1;
    if(x&&c=='x'&&f==s)return 1;
    if(!x&&c=='o'&&f==s)return 1;
    if(!x&&c=='x'&&f!=s)return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    cin>>s;
    s="^"+s;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            a[1]=i;a[2]=j;
            for(int k=3;k<=n;k++){
                if(a[k-1]==0&&s[k-1]=='o')a[k]=a[k-2];
                if(a[k-1]==0&&s[k-1]=='x')a[k]=a[k-2]^1;
                if(a[k-1]==1&&s[k-1]=='o')a[k]=a[k-2]^1;
                if(a[k-1]==1&&s[k-1]=='x')a[k]=a[k-2];
            }
            if(check(a[1],s[1],a[n],a[2])&&check(a[n],s[n],a[1],a[n-1])){
               for(int i=1;i<=n;i++){
                    if(a[i])printf("W");
                    else printf("S");
                }
                return 0;
            }
        }
    }
    puts("-1");
}
