#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint>PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int N,a[100010];
int ans=0,ans1=0;;

signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N;
    rep(i,0,N)cin>>a[i];
    sort(a,a+N);
    if(N%2==0){
         rep(i,N/2,N){
            if(i==N/2)ans+=a[i];
            else ans+=2*a[i];
        }
        rep(i,0,N/2){
           if(i==N/2-1)ans-=a[i];
           else ans-=2*a[i];
        }
    }else{
        rep(i,N/2,N)ans+=2*a[i];
        ans-=a[N/2]+a[N/2+1];
        rep(i,0,N/2)ans-=2*a[i];
        rep(i,N/2+1,N)ans1+=2*a[i];
        rep(i,0,N/2+1)ans1-=2*a[i];
        ans1+=a[N/2]+a[N/2-1];
        //cout<<ans<<" "<<ans1<<endl;
        chmax(ans,ans1);
    }
    cout<<ans<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}