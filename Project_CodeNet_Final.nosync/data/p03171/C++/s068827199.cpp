#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp12            make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pq1             priority_queue<int>
#define pqr1            priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void FIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int modInv(int a,int b,int m){int res=1;a=a%m;while(b>0){if(b&1){res=(res*a)%m;}a=(a*a)%m;b=b>>1;}return res;}

int dp[3001][3001];

int func(int i,int j,int n,int a[]){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int op1=a[i]+min(func(i+2,j,n,a),func(i+1,j-1,n,a));
    int op2=a[j]+min(func(i+1,j-1,n,a),func(i,j-2,n,a));
    return dp[i][j]=max(op1,op2);
}

void solve(){
	int n;
    cin>>n;
    int a[n];
    memset(dp,-1,sizeof(dp));
    int s=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        s+=a[i];
    }
    int e=func(0,n-1,n,a);
    int w=s-e;
    cout<<e-w;
}
    

int32_t main()
{
   // FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
