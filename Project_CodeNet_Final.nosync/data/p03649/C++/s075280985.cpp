#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
const int mod=1e9+7;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL a[55];
int main(){
//    freopen("out.txt","r",stdin);
//    freopen("outt.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int f=1;
    LL ans=0;
    while(f){
        f=0;
        for(int i=0;i<n;i++){
            if(a[i]>=n){
                f=1;
                LL k=a[i]/n;
                ans+=k;
                a[i]%=n;
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    a[j]+=k;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
