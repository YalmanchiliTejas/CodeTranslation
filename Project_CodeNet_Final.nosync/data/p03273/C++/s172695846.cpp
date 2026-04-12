#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef pair<int,int> P;
typedef long long ll;

int main(){
	int h,w;
	char s[100][101];

	cin >> h >> w;
	for(int i=0;i<h;i++){
		cin >> s[i];
	}
	bool x[100];
	bool y[100];
	for(int i=0;i<100;i++){
		x[i] = false;
		y[i] = false;
	}

	for(int i=0;i<h;i++){
		bool tmp = true;
		for(int j=0;j<w;j++){
			if(s[i][j]=='#'){
				tmp = false;
			}
		}
		if(tmp) x[i] = true;
	}
	for(int i=0;i<w;i++){
		bool tmp = true;
		for(int j=0;j<h;j++){
			if(s[j][i]=='#'){
				tmp = false;
			}
		}
		if(tmp) y[i] = true;
	}

	for(int i=0;i<h;i++){
		if(x[i]) continue;
		for(int j=0;j<w;j++){
			if(!y[j]){
				cout << s[i][j];
			}
		}
		cout << endl;
	}
	

	return 0;
}