#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y;
	cin >> A >> B >> C >> X >> Y;

	int p = min(X,Y);

	int ans = min(2*C*p+A*(X-p)+B*(Y-p), A*X+B*Y);
	ans = min(ans, 2*C*max(X,Y));

	cout << ans << endl;


}