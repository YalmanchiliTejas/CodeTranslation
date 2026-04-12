#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> S;
	LL count = 0;
	for(int i=0; i<H; i++){
		string s;
		for(int j=0; j<W; j++){
			char c; cin >> c;
			s.push_back(c);
			if(c == '#'){
				count++;
			}
		}
		S.push_back(s);
	}
	if(count == H-1+W-1+1){
		printf("Possible\n");
	}
	else{
		printf("Impossible\n");
	}
	return 0;
}
