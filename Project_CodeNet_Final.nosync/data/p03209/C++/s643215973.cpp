#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
vector<ll> h(51);
vector<ll> p(51);
ll length_b(int N){//バーガーの層の数
	if (N == 0){
		return h[0] = 1;
	}
	else{
		return h[N] = length_b(N - 1) * 2 + 3;
	}
}

ll paty(int N){//パティの数
	if (N == 0){
		return p[0] = 1;
	}
	else{
		return p[N] = paty(N - 1) * 2 + 1;
	}
}
ll  solve(int N,ll X){
	if (N == 0 && X >= 1){
		return 1;
	}
	else if (X == 0){
		return 0;
	}
	if (X < (h[N]/2 + 1)){
		// cout << "1" << "N"<< N << "X" <<  h[N]/2 + 1 << "h[N]" << h[N] <<  endl;		
		return solve(N - 1,X - 1);
	}
	else if(X == (h[N]/2 + 1)){
		// cout << "2" <<  "N"<< N << "X" <<  h[N]/2 + 1 << "h[N]" << h[N] <<  endl;
		return 1 + solve(N - 1,X -2);
	}
	else{
		// cout << "3" << "N"<< N << "X" <<  h[N] /2 + 1 << "h[N]" << h[N] <<  endl;
		return solve(N - 1, X - (h[N] / 2 + 1)) + 1 + p[N - 1]; 
	}
}
int main(){
	int N;
	ll X;
	cin >> N >> X;
	length_b(N);
	paty(N);

	cout << solve(N,X) << endl;

	return 0;
}