#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h;
	int w;
	cin >> h;
	cin >> w;
	char a[h][w];
	for(int i = 0; i < h; i++){
		string s;
		cin >> s;
		for(int j = 0; j < w; j++){
			a[i][j] = s[j];
		}
	}
	for(int i = 0; i < h; i++){
		bool flag3 = false;
		for(int k = 0; k < w; k++){
			bool flag = true;
			for(int j = 0; j < w; j++){
				if(a[i][j]=='#'){
					flag = false;
					flag3 = true;
					break;
				}
			}
			bool flag2 = true;
			for(int j = 0; j < h; j++){
				if(a[j][k]=='#'){
					flag2 = false;
					break;
				}
			}
			if(!(flag||flag2)){
				cout << a[i][k];
			}
		}
		if(flag3)cout << endl;
	}
}
