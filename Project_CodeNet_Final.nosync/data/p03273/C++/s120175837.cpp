#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000007
#define LINF 1000000000000000007
 
typedef long long ll;
typedef pair<ll,ll> P;


int h,w;
string s[101];

int main(){
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> s[i];
	}
	
	bool b[100] = {0}, bb[100] = {0};
	for(int i = 0; i < 100; i++){
		int c = 0;
		for(int j = 0; j < w; j++){
			if(s[i][j] == '#') c++;
		}
		if(c == 0) b[i] = 1;
		c = 0;
		for(int j = 0; j < h; j++){
			if(s[j][i] == '#') c++;
		}
		if(c == 0) bb[i] = 1;
	}
	
	for(int i = 0; i < h; i++){
		if(b[i]) continue;
		for(int j = 0; j < w; j++){
			if(bb[j]) continue;
			cout << s[i][j];
		}
		cout << endl;
	}
	
	return 0;
}