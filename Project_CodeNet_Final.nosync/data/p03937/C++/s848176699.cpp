#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli h, w;

int main(void){
	cin >> h >> w;
	lli c = 0;
	rep(i, h){
		string s;
		cin >> s;
		rep(j, s.size()){
			if(s[j] == '#') c++;
		}
	}
	if(c == h+w-1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}
