#include<bits/stdc++.h>
using namespace std;
char yo(char s){return (s == 'S' ? 'W' : 'S');}
int main(){
	int n;
	string s;
	cin >> n >> s;
	string a[] = {"SS", "SW", "WS", "WW"};
	for(int i = 0; i < 4; ++i){
		string po = a[i];
		for(int j = 1; j < n; ++j){
			if(po[j] == 'S'){
				if(s[j] == 'o') po += po[j - 1];
				else po += yo(po[j - 1]);
			}else{
				if(s[j] != 'o') po += po[j - 1];
				else po += yo(po[j - 1]);
			}
		}
		if(po[0] != po[n]) continue;
		if(s[0] == 'o'){
			if((po[0] == 'S' && po[1] == po[n - 1]) || (po[0] == 'W' && po[1] != po[n - 1])){
				cout << po.substr(0, n) << endl;
				return 0;
			}
		}else{
			if((po[0] == 'W' && po[1] == po[n - 1]) || (po[0] == 'S' && po[1] != po[n - 1])){
				cout << po.substr(0, n) << endl;
				return 0;
			}
		}

	}
	cout << "-1\n";
	return 0;
}