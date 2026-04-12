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
int main(){
	int H,W;
	char l;
	cin >> H >> W;
vector<vector<char>> v(H,vector<char>(W));

	for (int i = 0;i< H;i++){
		for (int j = 0;j < W;j++){
			cin >> l;
			v[i][j] = l;
		}
	}
	for (int i = 0;i< H;i++){
		int flag = 0;
		for (int j = 0;j < W;j++){
			if (v[i][j] == '#'){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			for (int j = 0;j < W;j++){
				v[i][j] = '0';
			}
		}
	}

	for (int i = 0;i< W;i++){
		int flag = 0;
		for (int j = 0;j < H;j++){
			if (v[j][i] == '#'){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			for (int j = 0;j < H;j++){
				v[j][i] = '0';
			}
		}
	}
	for (int i = 0;i< H;i++){
		int flag = 0;
		for (int j = 0;j < W;j++){
			if (v[i][j] != '0'){
				cout  << v[i][j];
			}
		}
		for (int j = 0;j < W;j++){
			if (v[i][j] == '0'){
				continue;
			}
			else{
				flag = 1;
				break;
			}
		}
		if (flag == 1){
			cout << endl;

		}
	}
	return 0;
}