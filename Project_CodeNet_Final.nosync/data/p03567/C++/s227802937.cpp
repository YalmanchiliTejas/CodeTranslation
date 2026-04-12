#include <bits/stdc++.h>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const int inf = 1e9;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int l;
	l = s.size();
	int ans = 0;
	for(int i=0;i<l-1;i++){
		if(s[i]=='A' && s[i+1]=='C'){
			ans = 1;
			break;
		}
	}
	if(ans==1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	

	return 0;
}