#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int h, w;
	cin >> h >> w;
	char tavolo[h][w];
	vector<int> damenaH;
	vector<int> damenaW;
	for( int i = 0; i < h; ++i ){
		bool flag = true;
		for( int j = 0; j < w; ++j ){
			char temp;
			cin >> temp;
			if( temp == '#' ) flag = false;
			tavolo[i][j] = temp;
		}
		if( flag ) damenaH.push_back(i);
	}
	for( int i = 0; i < w; ++i ){
		bool flag = true;
		for( int j = 0; j < h; ++j ){
			if( tavolo[j][i] == '#' ) flag = false;
		}
		if( flag ) damenaW.push_back(i);
	}
	for( int i = 0; i < h; ++i ){
		if( find( damenaH.begin(), damenaH.end(), i ) != damenaH.end() ) continue;
		for( int j = 0; j < w; ++j ){
			if( find( damenaW.begin(), damenaW.end(), j ) != damenaW.end() ) continue;
			cout << tavolo[i][j];
		}
		cout << endl;
	}
	return 0;
}