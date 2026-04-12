#include <bits/stdc++.h>
#define r second
#define l first
#define f first
#define s second
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<ll,ll> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 3e3 + 10;

int N;
vector<int> V;

ll DPf[MAX][MAX][2];
ll DPs[MAX][MAX][2];

pii solve(int l, int r, bool p){
	if(DPf[l][r][p] != -1) return {DPf[l][r][p],DPs[l][r][p]};

	pii ans;

	if(l == r){
		if(p) return {V[l],0};
		else return {0,V[l]};
	}

	if(p){
		if(V[l] + solve(l+1,r,!p).f > V[r] + solve(l,r-1,!p).f){
			ans.l = V[l] + solve(l+1,r,!p).f;
			ans.r = solve(l+1,r,!p).s;
		}
		else{
			ans.l = V[r] + solve(l,r-1,!p).f;
			ans.r = solve(l,r-1,!p).s;
		}
	}
	else{
		if(V[l] + solve(l+1,r,!p).s > V[r] + solve(l,r-1,!p).s){
			ans.r = V[l] + solve(l+1,r,!p).s;
			ans.l = solve(l+1,r,!p).f;
		}
		else{
			ans.r = V[r] + solve(l,r-1,!p).s;
			ans.l = solve(l,r-1,!p).f;
		}
	}

	DPf[l][r][p] = ans.f;
	DPs[l][r][p] = ans.s;

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	memset(DPf, -1, sizeof DPf);
	memset(DPs, -1, sizeof DPs);
	V.resize(N);

	for(auto &x : V) cin >> x;

	pii ans = solve(0,N-1,1);

	cout << ans.l - ans.r << endl;

	return 0;
}
