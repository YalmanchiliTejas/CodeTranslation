#include <bits/stdc++.h>
 
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
 
using namespace std;

ll dp[111][4][2];
string n;
int k;

ll solve(int i, int n0, bool less){
	if(n0 > k) return 0;
	if(i == (int) n.size()) return n0==k;
	ll &aux = dp[i][n0][less];
	if(aux!=-1) return aux;
	aux =0;

	if(less){
		for(int j=0;j<10;j++){
			aux += solve(i + 1, n0 + (j > 0), true);
		}
	}
	else{
		int dig = int(n[i] - '0');
		for(int j=0;j<dig;j++){
			aux+= solve(i+1, n0 + (j > 0), true);
		}
		aux+= solve(i + 1, n0 + (dig>0), false);
	}

	return aux;
}
 
int32_t main(){
	memset(dp,-1, sizeof dp);

	cin >> n >> k;
	cout << solve(0,0,0) << endl;
	return 0;
}