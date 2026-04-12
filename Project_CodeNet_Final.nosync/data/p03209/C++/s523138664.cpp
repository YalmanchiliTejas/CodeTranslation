#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}


vector<vector<ll>> bargers(51, vector<ll>());
vector<ll> make_barger(int level){

	if(level == 0){
		vector<ll> vec = {1};
		return vec;
	}
	if(level == 1){
		vector<ll> vec = {1, 3, 1};
		return vec;
	}
	if(bargers[level].size() != 0) return bargers[level];
	
	vector<ll> left = make_barger(level - 1);
	vector<ll> right = left;
	left[0]++;		right.back()++;
		
	vector<ll> barger = left;
	barger.push_back(1);
	barger.insert(end(barger), begin(right), end(right));//barger.push_back(right);

	return bargers[level] = barger;
	
}


ll calc(int level, ll X){

	// an = 2 a_n-1  + 3 を解くと
	// an = 4 2^n  -3  　なので  a_n-1 = 4 2^(n-1) -3	
	ll a_n_1 = 4 * pow((ll)2, level-1) -3; 	
	ll a_n =   4 * pow((ll)2, level)   -3;
	// ll a_n_1 = (ll)4*((ll)1 << (level-1)) - 3; 	
	// ll a_n =  (ll)4 * ((ll)2 << (level)) -3;
	//if(X == 0) return 0;
	if(level == 0 && X <= 0) return 1;
	if(level == 0) return 1;
	
	if(X == 1) return 0;
	if(X <= a_n_1 + 1) return calc(level-1, X - 1);
	if(X == a_n_1 + 2) return calc(level-1, a_n_1) + 1;
	if(X == a_n) return 2 * calc(level-1, a_n_1) + 1;
	return calc(level-1, a_n_1) + 1 + calc(level-1, X-a_n_1-2);// (B  レベルN-1   p) の中のパティの個数  +  レベルN-1の途中のパティの個数
	// ll p_n_1 = pow(2, level) - 1; // pn = 2^(n+1) - 1;  // pn = 1 + 2pn_1を解いた
	// if(X == a_n_1 + 2) return p_n_1 + 1;
	// if(X == a_n) return 2 * p_n_1 + 1;
	// return p_n_1 + 1 + calc(level-1, X-a_n_1-2);
}

int main(){
	int N;
	ll X;
	cin >> N >> X;
	// vector<ll> barger = make_barger(N);

	// ll ans = 0;
	// for(ll i=0; i<barger.size(); i++){
	// 	if(i%2 == 1) ans += min(X, barger[i]);
	// 	X -= barger[i];
	// 	if(X <= 0) break;
	// }


	ll ans = calc(N, X);
	cout << ans << endl;

}

