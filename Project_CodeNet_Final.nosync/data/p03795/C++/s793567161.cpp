#include<bits/stdc++.h>
using namespace std;
int main() {
	int N,M,Y;
	Y = 0;
	cin >> N;
	M = N * 800;
	
	for (int  i = 1; i <= N; i++)
	{
		if (i % 15 == 0) {
			Y+=200;
		}
	}
	cout << M - Y << endl;



}