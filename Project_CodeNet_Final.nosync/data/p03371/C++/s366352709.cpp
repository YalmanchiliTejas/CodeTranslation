#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int Nmax=200010;
//#define FOR(i,a,b) for(int i=(a);i<(b);i++)
//#definr REP(i,n) FOR(i,0,n)
//#define dump(x) cout << #x << "=" << (x) << endl;
//#define debug(x) cout << #x << "=" << (x) << "(L" << _LINE_ << ")" << "" << _FILE_ << endl;
//ll a[Nmax];
//int* P = new int[N];

int main() {
	int A,B,C,X,Y;
	ll price=0;
	cin >> A >> B >> C >> X >> Y;
	
	if((A+B)/2 >= C){
		price += 2*C*min(X,Y);
	
		if(max(X,Y) == X){//Aを買い足し
			if(A >= 2*C) price += 2*C*(X-Y);
			else price += A*(X-Y);
		}else{
			if(B >= 2*C) price += 2*C*abs(Y-X);
			else price += B*abs(Y-X);
		}
	}else{
		price += X*A + Y*B;
	}
	cout << price << endl;
	
	return 0;
}