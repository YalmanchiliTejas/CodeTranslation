#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B, C, X, Y;
	cin>>A>>B>>C>>X>>Y;

	int res = X * A + Y * B;
	for(int i = 1; i <= max(X, Y); i ++){
		res = min(res, max((X - i), 0) * A + max((Y - i), 0) * B + 2 * i * C);
	}
	cout<<res<<endl;
}