#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=110;
    int K;
    char N[MAXN];
    ll C(int n,int k){
        if(n<0||k<0)return 0;
        ll r=1;
        for(int u=n-k+1;u<=n;u++)r*=u;
        for(int u=1;u<=k;u++)r/=u;
        return r;
    }
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>N>>K;
        ll ans=0;
        int len=strlen(N);
        int nz=0;
        for(int u=0;u<len;u++){
            int x=N[u]-'0';
            if(N[u]=='0'||nz>K)continue;
            ans+=(x-1)*C(len-u-1,K-nz-1)*pow(9,K-nz-1);
            ans+=C(len-u-1,K-nz)*pow(9,K-nz);
            nz++;
        }
        if(nz==K)ans++;
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}