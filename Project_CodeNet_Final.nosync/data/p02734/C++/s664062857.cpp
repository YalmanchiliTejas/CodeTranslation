#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define endl '\n'
#define y1 holyshit
const int inf=0x3f3f3f3f;
const int mod=998244353;

int N,S,d[3010];
ll cnt[3010],cnt2[3010],ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>N>>S;
    for(int i=1;i<=N;i++) cin>>d[i];
    for(int i=1;i<=N;i++){
    	cnt[0]=i;
    	for(int j=d[i];j<3010;j++) cnt2[j]=(cnt[j]+cnt[j-d[i]])%mod;
    	for(int j=0;j<3010;j++)cnt[j]=cnt2[j];
    	ans=(ans+cnt[S])%mod;
    }
    cout<<ans;
    return 0;
}