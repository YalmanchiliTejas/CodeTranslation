#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long
#define int long long
#define ld long double
#define endl '\n'
const int mod= 1e9+7;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define trace(x) cerr << #x << " is " << x << endl;
#define all(x) x.begin(),x.end()
#define reset(x,val) memset(x,val,sizeof(x))
#define flush fflush(stdout)
#define sz(a) a.size()
#define pii pair<int,int>
using namespace std;
const int N=3003;
int n,a[N],cache[N][N];
int dp(int i,int j,int turn)
{
 if(j<i)return 0;
 int &ans=cache[i][j];
 if(ans!=-1)return ans;
 
 if(turn==0)
 {
  ans=max(a[i]+dp(i+1,j,1),a[j]+dp(i,j-1,1));
 }
 else
 {
  ans=min( -a[i]+dp(i+1,j,0) , -a[j]+dp(i,j-1,0) );
 }
 return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    reset(cache,-1);
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<dp(1,n,0);
    
    return 0;
}

