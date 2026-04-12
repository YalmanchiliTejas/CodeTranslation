#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MOD 1000000007
#define pi 3.141592653589793238
#define ll long long int
#define P pair<ll, ll>
#define VII vector<P>
#define P_B push_back

int n, k;
ll v[3000];
ll DP[3000][3000];

ll backtrack(int beg, int end) {

	if(beg > end) return 0;	
	if(DP[beg][end] != -1) return DP[beg][end];
	
	return DP[beg][end] =  max(v[beg] - backtrack(beg+1, end), v[end] - backtrack(beg, end-1));
}

int main() {
	
	// ll T; cin>>T; while(T--) 
	{
		
		int n;
		cin>>n;
		memset(DP, -1, sizeof(DP));
		for (int i = 0; i < n; i++) cin>>v[i];
		cout<<backtrack(0, n-1);

	}	
	return 0;
}