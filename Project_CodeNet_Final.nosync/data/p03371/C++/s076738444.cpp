#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const int INF=2e9;

int main(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int M=max(X,Y), res=INF;
	for(int i=0; i<=M*2; i+=2){
		int a=max(0,X-i/2), b=max(0,Y-i/2);
		res=min(res,a*A+b*B+C*i);
	}
	cout << res << endl;

	return 0;
}