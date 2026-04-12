#include<bits/stdc++.h>
using namespace         std;
#define                 int long long
#define                 pb push_back
#define                 mp make_pair
#define st(arr,a)       memset(arr,a,sizeof arr)
#define                 nl cout<<endl
#define                 real signed
#define                 endl '\n'              
#define bitcount(x)     __builtin_popcountll(x)
const int MOD = 1000000007ll;
#define forn(i,a,b)     for(int i=a;i<=b;i++)
#define rfor(i,a,b)     for(int i=a;i>=b;i--)
#define all(x)          x.begin() , x.end()
#define pi pair<int,int>
#define X first
#define Y second
#define N 3141

int dp[N][N][2];

int n;
int arr[3141];

int get(int start,int end,int chance)
{
	if(start>end)return 0;
	//if(start==end)return arr[start];

	int&ans=dp[start][end][chance];
	if(ans!=MOD*MOD)return ans;

	if(chance==0)
	{
		ans=max(arr[start]+get(start+1,end,1),arr[end]+get(start,end-1,1));

	}
	else ans=min(get(start+1,end,0)-arr[start],get(start,end-1,0)-arr[end]);
	return ans;
}

signed main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    forn(i,0,3000)forn(j,0,3000)forn(k,0,1)dp[i][j][k]=MOD*MOD;
	cin>>n;
	forn(i,1,n)cin>>arr[i];
//	forn(i,1,n)cout<<arr[i]<<" ";nl;
	
	cout<<get(1,n,0);
	
	
    return 0;

}

//       g++ -g c.cpp ; ./a.exe