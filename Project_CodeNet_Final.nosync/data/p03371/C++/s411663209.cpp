#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B,C ; cin >>A>>B>>C;
	int minA,minB,minAB; minA = min(A,2*C);minB = min(B,2*C);
	minAB = min(A+B,2*C);
	int X,Y; cin >>X>>Y;
	if(X > Y)
	cout << min(X,Y)*minAB + (X-Y)*minA << endl;
	if(X <= Y)
	cout << min(X,Y)*minAB + (Y-X)*minB << endl;
}