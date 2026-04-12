#include<iostream>
#include <string> 
#include <vector>  
#include<math.h>

#define INF 1000000000
#define LM 55555
using namespace::std;


long Lmax(long x, long y) {
	if (x > y)return x;
	return y;
}

int max(int x, int y) {
	if (x > y)return x;
	return y;
}

long Lmin(long x, long y) {
	if (x < y)return x;
	return y;
}


int min(int x, int y) {
	if (x < y)return x;
	return y;
}

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int A,B,C,X,Y,N, M[LM],num,v[55555],ch,ans;
string s[50], t[100];
int chx[4] = { 1,0,0,-1 };
int chy[4] = { 0,1,-1,0 };
bool a, b, c;
int main() {
	cin >> A >> B >> C >> X >> Y;
	ans = 0;
	if (A + B > 2 * C) {
		ans += 2 * C*min(X, Y);
		if (X > Y) {
			if (A < 2 * C) {
				ans += (X - Y)*A;
			}
			else {
				ans += (X - Y)*2*C;
			}
		}
		else {
			if (B < 2 * C) {
				ans += (Y - X)*B;
			}
			else {
				ans += (Y - X) * 2 * C;
			}
		}
	}
	else {
		ans = A*X + B*Y;
	}
	cout<< ans << endl;
	return 0;
}


