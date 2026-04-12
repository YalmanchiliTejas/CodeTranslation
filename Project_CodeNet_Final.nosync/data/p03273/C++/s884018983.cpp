#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main(){
	int h, w; cin >> h >> w; std::vector<std::string> s(h);
	for(int i = 0; i < h; i++) cin >> s[i];
	
	std::vector<bool> A(h, true), B(w, true);
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) if(s[i][j] == '#') A[i] = false;
		
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++) if(s[j][i] == '#') B[i] = false;
		
	for(int i = 0; i < h; i++) {
		if(A[i]) continue;
		for(int j = 0; j < w; j++) {
			if(B[j]) continue;
			cout << s[i][j];
		}
		cout << endl;
	}
	return 0;
}
