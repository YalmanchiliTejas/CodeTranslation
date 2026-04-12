#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
string s;
vector<int> ans;
int f = -1;

int main(){
	cin >> n >> s;
	vector<int> si(n);
	rep(i, n){
		if(s.at(i) == 'o'){
			si.at(i) = 1;
		}else{
			si.at(i) = -1;
		}
	}
	vector<vector<int>> a(4, vector<int>(n));
	vector<int> b(4);
	ans = vector<int>(n);
	rep(i, 4) rep(j, n) a.at(i).at(j) = 22;
	if(s.at(0) == 'o'){
		a.at(0).at(0) = 1; a.at(0).at(1) = 1; b.at(0) = 1;
		a.at(1).at(0) = 1; a.at(1).at(1) =-1; b.at(1) =-1;
		a.at(2).at(0) =-1; a.at(2).at(1) = 1; b.at(2) =-1;
		a.at(3).at(0) =-1; a.at(3).at(1) =-1; b.at(3) = 1;
	}else{
		a.at(0).at(0) = 1; a.at(0).at(1) = 1; b.at(0) =-1;
		a.at(1).at(0) = 1; a.at(1).at(1) =-1; b.at(1) = 1;
		a.at(2).at(0) =-1; a.at(2).at(1) = 1; b.at(2) = 1;
		a.at(3).at(0) =-1; a.at(3).at(1) =-1; b.at(3) =-1;
	}
	rep(i, 4){
		for(int j=2; j<n; j++){
			a.at(i).at(j) = a.at(i).at(j-2) * a.at(i).at(j-1) * si.at(j-1); 
		}
		if(a.at(i).at(n-1) == b.at(i)){
			if(si.at(n-1) * a.at(i).at(n-2) * a.at(i).at(n-1) == a.at(i).at(0)){
				f = i;
				break;
			}
		}
	}
	if(f != -1){
		rep(i, n){
			if(a.at(f).at(i) == -1){
				cout << 'W';
			}else{
				cout << 'S';
			}
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}