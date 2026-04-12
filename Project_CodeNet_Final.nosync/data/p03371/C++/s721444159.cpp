#include<bits/stdc++.h>
using namespace std;

int main(){
	
	long A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	long  ans = A*X+B*Y;

	ans = min(C*max(X,Y)*2, ans);

	long  z=0;
	if(X>Y){
		z = C*Y*2 + (X-Y)*A;
	}
	else
	{
		z = C*X*2 + (Y-X)*B;
	}
	ans = min(z, ans);

	cout << ans << endl;
	
	return 0;
}