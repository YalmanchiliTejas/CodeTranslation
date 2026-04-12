#include <bits/stdc++.h>
using namespace std;
char tab[105][105];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int a,b; cin>>a>>b;
	for(int i = 1; i <= a; i ++){
		for(int j = 1; j <= b; j ++){
			cin >> tab[i][j];
		}
	}
	for(int i = 1; i <= a; i ++){
		bool czy = true;
		for(int j = 1; j <= b; j ++){
			if(tab[i][j] == '#'){
				czy = false;
				break;
			}
		}
		if(czy){
			for(int j = 1; j <= b; j ++){
				tab[i][j] = '?';
			}
		}
	}
	for(int i = 1; i <= b; i ++){
		bool czy = true;
		for(int j = 1; j <= a; j ++){
			if(tab[j][i] == '#'){
				czy = false;
				break;
			}
		}
		if(czy){
			for(int j = 1; j <= a; j ++){
				tab[j][i] = '?';
			}
		}
	}
	for(int i = 1; i <= a; i ++){
		bool xd = false;
		for(int j = 1; j <= b; j ++)
			if(tab[i][j] != '?') cout << tab[i][j], xd = true;
		if(xd) cout << '\n';
	}
}