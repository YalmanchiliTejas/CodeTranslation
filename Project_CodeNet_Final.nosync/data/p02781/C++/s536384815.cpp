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
 
 //dp[i][j][m]: Nを上から見た時に
 //i-1桁目まで考慮し，非0がj個ある個数
 //mはフラグ (i-1桁目まで考慮したときに既にNより小さい数になることが確定しているか否か)
 // i-1までの桁がNと一致⇒m=0,  i-1までの桁を考慮した時点でNより小さい数になることが確定⇒m=1
 	int dp[101][4][2];
int main(){
	string s;
	cin >> s;
	int K;
	cin >> K;
	int N = s.size();

	dp[0][0][0] = 1;//まだ1桁も考慮してない時点ではNと一致しているといえるので1個
	for(int i=0; i<N; i++){
	for(int j=0; j<=3; j++){
	for(int m=0; m<=1; m++){
				
		int nd = s[i] - '0';
		for(int num=0; num<=9; num++){
			int ni = i+1, nj = j, nm = m;
			if(num!=0) nj++;
			if(nj>K) continue;
			if(m==0 && num>nd) continue;
			if(m==0 && num<nd) nm=1;
			dp[ni][nj][nm] += dp[i][j][m];
		}
	}
	}
	}
	// cout << " dp[N-1][K][0]: " << dp[N-1][K][0] << " dp[N-1][K][1]: " << dp[N-1][K][1] << endl;
	// cout << " dp[N-1][K-1][0]: " << dp[N-1][K-1][0] << " dp[N-1][K-1][1]: " << dp[N-1][K-1][1] << endl;
	
	// cout << " dp[N][K][0]: " << dp[N][K][0] << " dp[N][K][1]: " << dp[N][K][1] << endl;
	int ans = dp[N][K][0] + dp[N][K][1];
	cout << ans << endl;
	return 0;



}
