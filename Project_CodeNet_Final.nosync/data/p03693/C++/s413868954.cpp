#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main(){
	int r, g, b;
	cin >> r >> g >> b;
	if((r*100+10*g+b)%4) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}