#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;

	int lis[3];
	if(X > Y){
		lis[0] = 2*C*X;
		lis[1] = 2*C*Y+(X-Y)*A;
	}else{
		lis[0] = 2*C*Y;
		lis[1] = 2*C*X+(Y-X)*B;
	}

	lis[2] = A*X+B*Y;

	cout << min(lis[0], min(lis[1],lis[2])) << endl;

	return 0;
}
