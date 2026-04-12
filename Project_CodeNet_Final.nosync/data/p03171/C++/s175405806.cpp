/*input
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1


*/ 
#include <iostream>
#include <bits/stdc++.h>
#include <math.h> 
    
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define gc getchar_unlocked
#define fo(i,n) for(ll i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define ms(a,x) memset(a, x, sizeof(a));
#define endl "\n"
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 1000000001;
const int MAX = 1e5+1;
int ans = 0;
int dp[3000][3000][2];
int  fn(int arr[],int n,int l,int r,int point){
	if(l>r){ 
		return 0;
	}
	if(dp[l][r][point]!=-1) return dp[l][r][point];
	if(!point){
		dp[l][r][point] = max(arr[l]+fn(arr,n,l+1,r,(point+1)%2),arr[r]+fn(arr,n,l,r-1,(point+1)%2));

	}
	else{
		dp[l][r][point] = min(-arr[l]+fn(arr,n,l+1,r,(point+1)%2),-arr[r]+fn(arr,n,l,r-1,(point+1)%2));
	}
	//cout<<dp[l][r][point]<<" "<<l<<" "<<r<<' '<<point<<endl;
	return dp[l][r][point];
}
int32_t main() {
    IOS;
	int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		dp[i][j][0] = -1;
    		dp[i][j][1] = -1;
    	}
    }
    int ans = fn(arr,n,0,n-1,0);
	//cout<<dp[k][n]<<endl;
	cout<<dp[0][n-1][0]<<endl;
	return 0;
}




