#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace std;
#define int long long int
#define double long double
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> new_data_set;
bool isprime(int n)
	{
    	if(n==1) return true;
    	for(int i = 2;i*i<=n;i++){
    		if(n%i==0) return false;
		}
		return true;
	}
int lcm(int a,int b){
	return (a*b)/__gcd(a,b);
}
int gcd(int a, int b) 
{ 
    if (b == 0){
    	return a;
	} 
    return gcd(b, a % b);  
      
} 
unsigned int factorial(unsigned int n) 
{ 
    if (n == 0) 
    return 1; 
    return n * factorial(n - 1); 
} 
const int inf=1e17+7;
int dsu[1000001],s[100005];
void init(int n,int m){
	for(int i=1;i<=n;i++){
		dsu[i]=i;
		s[i]=1;
	}
}
int root(int x){
	while(dsu[x]!=x){
		x = dsu[x];
	}
	return x;
}
void uni(int x,int y){
	int p = root(x);
	int q = root(y);
	if(p==q){
		return;
	}
	else{
		if(s[p]<s[q]){
			s[q]+=s[p];
			dsu[p] = q;
		}
		else{
			s[p]+=s[q];
			dsu[q] = p;
		}
	}
}
int power(int x, unsigned int y)  
{  
    int res = 1;
    x = x ; 
    if (x == 0) return 0;  
    while (y > 0){  
        if (y & 1)  
            res = (res);   
        y = y>>1;  
        x = (x*x);  
    }  
    return res;  
}
vector<int>graph[100001];
set<pair<int,int>>st;
char arr[1001][1001];
bool visit[1001][1001];
void dfs(int x,int y,int n,int m){
	st.erase({x,y});
	visit[x][y]=true;
	if(x<n-1 && arr[x+1][y]=='#' && !visit[x+1][y])dfs(x+1,y,n,m);
	if(x>0 && arr[x-1][y]=='#' && !visit[x-1][y])dfs(x-1,y,n,m);
	if(y<m-1 && arr[x][y+1]=='#' && !visit[x][y+1])dfs(x,y+1,n,m);
	if(y>0 && arr[x][y-1]=='#' && !visit[x][y-1])dfs(x,y-1,n,m);
}
signed main(){
	FAST
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==1){
		cout<<arr[1];
		return 0;
	}
	if(n==2){
		cout<<max(arr[1],arr[2])-min(arr[1],arr[2]);
		return 0;
	}
	pair<int,int>dp[n+1][n+1];
	int i=1,j=1,cnt=1;
	while(i!=1 || j!=n){
		if(i==j){
			dp[i][j]={arr[i],0};
			i++;
			j++;
		}
		else{
			if(arr[i]+dp[i+1][j].second>arr[j]+dp[i][j-1].second){
				dp[i][j]={arr[i]+dp[i+1][j].second,dp[i+1][j].first};
			}
			else{
				dp[i][j]={arr[j]+dp[i][j-1].second,dp[i][j-1].first};
			}
			i++;
			j++;
		}
		if(i>n-cnt+1){
			i=1;
			cnt++;
			j=cnt;
		}
	}
	if(arr[i]+dp[i+1][j].second>arr[j]+dp[i][j-1].second){
		dp[i][j]={arr[i]+dp[i+1][j].second,dp[i+1][j].first};
	}
	else{
		dp[i][j]={arr[j]+dp[i][j-1].second,dp[i][j-1].first};
	}
	int ans=dp[1][n].first-dp[1][n].second;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dp[i][j].first<<" "<<dp[i][j].second<<"    ";
//		}
//		cout<<endl;
//	}
	cout<<ans;			
}