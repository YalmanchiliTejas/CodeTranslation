#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

/*
  C = A-B とする
  先頭から C*iの石と、末尾から  C*iの石 を踏むことになる

*/
ll N;

int main(){
	cin >> N;
	
	
	vector<ll> S(N);
	for ( int i = 0; i < N; i++ )
		cin >> S[i];
	
	ll M = N-1;
	
	ll max_score = 0; // 1歩でゴールの場合
	for ( int C = 1; C < M-C; C++ ){
		ll score = 0;
		bool can_drown = M % C == 0;
		for ( int j = C; j < M-C; j += C ){
			if ( can_drown && j >= M-j )
				break;
			score += S[j] + S[M-j];
			//cout << C << "  " << score << endl;
			max_score = max( max_score, score );
		}
	}
	
	
	cout << max_score << endl;
	
	return 0;
}

