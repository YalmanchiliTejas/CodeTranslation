#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A, B, C, X, Y, Cost;
	cin >> A >> B >> C >> X >> Y;
	Cost = A * X + B * Y;
	for (int i = 1; i <= max(X, Y); i++) {
		if (A * max((X-i),0) + B * max((Y-i),0) + 2*C*i < Cost){
			Cost=A * max((X-i),0) + B * max((Y-i),0) + 2*C*i;
		}
		
	}
	cout <<Cost << endl;
  return 0;
}

 