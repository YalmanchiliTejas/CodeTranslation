#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;

int main() {
	int H,W;
	cin >> H >> W;
	vector<string> input;
	int cnt = 0;
	for(int i=0; i<H; i++) {
		string s;
		cin >> s;
		input.push_back(s);
		for(int j=0; j<W; j++)
			if(s[j] == '#')
				cnt++;
	}
	
	bool ok = true;
	if(cnt != H+W-1) ok = false;
	if(input[0][0] != '#') ok = false;
	
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			if(i==0 && j ==0) continue;
			int p = 0;
			//cout << ok << endl;
			if(input[i][j] == '#') {
				if(i>0 && input[i-1][j] == '#' ) p++; 
				if(j>0 && input[i][j-1] == '#' ) p++; 
				if(p!=1) ok = false;
			}
		}
	}
	if(ok) cout << "Possible" << endl;
	
	else cout << "Impossible" << endl;
	
	return 0;
}

