#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int INF = 1e9 +5;
const int nax = 3005;
const long M = 1000000007;
// double p[305][305][305];
// double ev[305][305][305];
ll dp[nax][nax];
// int visited[nax];
// int in_degree[nax];
// vector<int> edges[nax];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed;
	cout<<setprecision(10);
	int t;
	// cin>>t;
	t = 1;
	while(t--){
		int n,k;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int L = n-1;L>=0;L--){
			for(int R = 0; R<=n-1;R++){
				if(L>R){
					dp[L][R]=0;
				}
				else if(L==R){
					dp[L][R] = arr[L];
				}
				else{
					dp[L][R] = max(arr[L] - dp[L+1][R], arr[R]-dp[L][R-1]);
				}
			}
		}
		// string ans = dp[k] ? "First" : "Second";
		cout<< dp[0][n-1] << '\n';
	}
}