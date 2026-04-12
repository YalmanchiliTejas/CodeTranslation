#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
	
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = b * 10 + c;
	if(ans % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}