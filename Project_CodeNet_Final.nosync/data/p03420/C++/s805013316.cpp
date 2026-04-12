#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


#define int ll


int n,k,x;

signed main(){
    cin>>n>>k;
    int cnt=0;
    repe(i,1,n){
        if(i<=k)continue;
        cnt+=(n/i)*(i-k);
        int y=(n/i)*(i-k);
        x=n%i-k+1;
        if(x>0){
            if(x+y<=n)cnt+=x;
            else cnt+=n-y;
        }
        
    }
    cout<<cnt<<endl;
    return 0;
}