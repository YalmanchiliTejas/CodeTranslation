#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;

	vector<int> a(M), b(M);
	vector<vector<int>> table(N, vector<int>(N, 0));
	for(int i=0; i<M; i++){
		cin >> a.at(i) >> b.at(i);
		table.at(a.at(i)-1).at(b.at(i)-1) = 1;
		table.at(b.at(i)-1).at(a.at(i)-1) = 1;
	}

	vector<int> v(N);
	for(int i =0; i<N; i++){
		v.at(i) = i+1;
	}

	int ans = 0;

	do{
		if(v.at(0) == 1){
			bool flg = true;
			for(int i=0; i<N-1; i++){
				if(table.at(v.at(i)-1).at(v.at(i+1)-1) == 0){
					flg = false;
					exit;
				}
			}
			if(flg) ans++;
		}
	}while(next_permutation(v.begin(), v.end()));

	cout << ans << endl;

}
