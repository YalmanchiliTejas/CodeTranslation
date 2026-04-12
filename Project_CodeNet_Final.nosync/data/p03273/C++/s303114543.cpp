#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	vector<string> v;
	string s;
	for (int i = 0; i < n; i++){
		cin >> s;
		bool b = true;
		for (int j = 0; j < m; j++){
			if (s[j] == '#'){
				b = false;
				break;
			}
		}
		if (!b){
			v.push_back(s);
		}
	}
	for (int i = 0; i < m; i++){
		bool b = true;
		for (int j = 0; j < v.size(); j++){
			if (v[j][i] == '#'){
				b = false;
				break;
			}
		}
		if (b){
			for (int j = 0; j < v.size(); j++){
				v[j].erase(v[j].begin() + i);
			}
			i--;
			m--;
		}
	}
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v[i].size(); j++){
			cout << v[i][j];
		}
		printf("\n");
	}
}