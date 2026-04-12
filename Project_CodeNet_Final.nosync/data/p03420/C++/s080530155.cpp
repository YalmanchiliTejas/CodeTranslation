#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define P pair<int,int>
#define vp vector<P>
#define PP pair<int,P>
#define vpp vector<PP>
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(x) (x).begin(),(x).end()
signed main(){
    int n,k;
    cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    int ans=0;
    FOR(i,k+1,n+1){
        //cerr<<i<<" "<<(i-k)*(n/i)+(n%i-k<0?0:n%i-k+1)<<endl;
        ans+=(i-k)*(n/i);
        if(n%i==k){
            ans++;
        }else if(n%i-k>=0){
            ans+=n%i-k+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}