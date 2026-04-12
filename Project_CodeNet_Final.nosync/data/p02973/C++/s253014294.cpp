#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int N;


int main(){
	cin >> N;
	vector<int> A(N);
	
	
	
	for ( int i = 0; i < N; i++ )
		cin >> A[i];
	
	deque<int> q; // 全ての色の、現在の最大値
	
	for ( int i = 0; i < N; i++ ){
		if ( q.empty() ){
			q.push_back( A[i] );
		}
		else {
			auto it = lower_bound(q.begin(), q.end(), A[i]);
			if ( it == q.begin() ){
				// このAより小さい色が無い。新しい色を用意する
				q.push_front( A[i] );
			}
			else {
				// 小さい色があるので、それを使う
				*(it-1) = A[i];
			}
		}
	}
	
	cout << q.size() << endl;
	
	
	return 0;
}

