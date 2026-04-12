#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=3e3+1;
ll dp[N][N][2];
vector<int> a(N);
ll n;

ll go(int l, int r, int mov){
    if(l>r) return 0;
    if(dp[l][r][mov]!=-1)
        return dp[l][r][mov];
    ll ans;
    if(mov==0)
        ans=max(a[l]+go(l+1,r,1^mov),a[r]+go(l,r-1,1^mov));
    else
        ans=min(go(l+1,r,1^mov)-a[l],go(l,r-1,1^mov)-a[r]);
    return dp[l][r][mov]=ans;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++)
        cin>>a[i];
    cout<<go(0,n-1,0);

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}