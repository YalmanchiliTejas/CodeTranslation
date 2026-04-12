#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;
 
int N,K=0,tmp=0,frag=1;

signed main() {
    IOS();
    cin>>N;
    vint a(N);
    rep(i,0,N)cin>>a[i];
    while(frag){
        frag=0;
        int x=0;
        rep(i,0,N){
            if(a[i]>=N){
                frag=1;
                int t=a[i]-N+1;
                if(t%N){
                    K+=t/N+1;
                    a[i]-=(t/N+1)*(N+1);
                    x+=t/N+1;
                }
                else{
                    K+=t/N;
                    a[i]-=t/N*(N+1);
                    x+=t/N;
                }
            }
        }
        rep(i,0,N)a[i]+=x;
    }
    cout<<K<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}