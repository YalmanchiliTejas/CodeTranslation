#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	vector<string> vec(n);
	for(int i = 0; i < n; ++i){
		cin>>vec[i];
	}
	for(int i = 0; i < n; ++i){
		if(vec[i][0] == '.'){
			bool ok = true;
			for(int j = 0; j < m; ++j){
				if(vec[i][j] == '#')ok = false;
			}
			if(ok){
				for(int j = 0; j < m; ++j){
					vec[i][j] = 'x';
				}
			}
		}
	}
	for(int j = 0; j < m; ++j){
		if(vec[0][j] == '.' || vec[0][j] == 'x'){
			bool ok = true;
			for(int i = 0; i < n; ++i){
				if(vec[i][j] == '#'){
					ok = false;
				}
			}
			if(ok){
				for(int i = 0; i < n; ++i){
					vec[i][j] = 'x';
				}
			}
		}
	}
	for(int i = 0; i < n; ++i){
		bool ok = false;
		for(int j = 0; j < m; ++j){
			if(vec[i][j] == '.' || vec[i][j] == '#')ok=true;
		}
		if(ok){
			for(int j = 0; j < m; ++j){
				if(vec[i][j] != 'x'){
					cout<<vec[i][j];
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
