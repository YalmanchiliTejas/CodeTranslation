#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

const ll M = 1000000007;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){
		ret *= x; ret %= M;
	}
	return ret;
}

int N;
ll h[102];

ll dp1[102][102];
ll dp2[102][102];
void solve(int l,int r,int d){
	if(l == r){
		dp1[l][r] = 0;
		dp2[l][r] = modpow(2,h[l]-d);
		return;
	}
	int d_ = M;
	for(int i = l ; i <= r ; i ++)d_ = min( (ll)d_ , h[i] );
	vector<P> vec;
	int l_=l,r_=l-1;
	int cnt = 0;
	for(int i = l ; i <= r ; i ++){
		if(h[i] <= d_){
			cnt ++;
			if(l_ <= r_){
				vec.push_back(P(l_,r_));
				solve(l_,r_,d_);
			}
			l_ = i+1;
			r_ = i;
		}
		else {
			r_ = i;
		}
	}
	if(l_ <= r_){
		vec.push_back(P(l_,r_));
		solve(l_,r_,d_);
	}
	dp1[l][r] = 1;
	dp2[l][r] = 1;
	for(int i = 0 ; i < vec.size() ; i ++){
		P p = vec[i];
		dp1[l][r] *= (dp1[p.fr][p.sc]+dp2[p.fr][p.sc]*2);
		dp1[l][r] %= M;
		dp2[l][r] *= dp2[p.fr][p.sc];
		dp2[l][r] %= M;
	}
	dp1[l][r] *= modpow(2,cnt);
	dp1[l][r] %= M;
	dp2[l][r] *= 2;
	dp2[l][r] %= M;
	dp1[l][r] += M-dp2[l][r];
	dp1[l][r] %= M;
	dp2[l][r] *= modpow(2,d_-d-1);
	dp2[l][r] %= M;
}

int main(){
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i ++){
		scanf("%lld",&h[i]);
	}
	solve(1,N,0);
	//cout << dp1[1][N] << " " << dp2[1][N] << endl;
	cout << (dp1[1][N]+dp2[1][N])%M << endl;
}

