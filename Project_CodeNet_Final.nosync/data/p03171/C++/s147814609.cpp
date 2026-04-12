#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
#define Fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define f(i, n) for (long long int i = 0; i < n; i++)
#define ll long long int
#define fo(i, a, b) for (long long int i = a; i <= b; i++)
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long int>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define mll map<ll,ll>
#define umll unordered_map<ll,ll>
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll inf = 1e9 + 7;
const ll modc = 998244353;
#define MAX 100002

ll maxi(ll a,ll b){
	if(a>=b)return a;
	return b;
}

int main(){
	Fio;
	ll n;
	cin>>n;
	vl A(n);
	f(i,n)cin>>A[i];
	ll dp[n+1][n+1] = {0};
	//dp[i][j] = x-y we can obtain in a[i:j]
	for(ll i = n-1;i>=0;i--){
		for(int j = i;j<n;j++){
			if(i==j)dp[i][j] = A[j];
			else dp[i][j] = maxi(A[i]-dp[i+1][j],A[j]-dp[i][j-1]);
		}	
	}
	cout<<dp[0][n-1];
	return 0;
}