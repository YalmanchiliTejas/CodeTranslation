
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<numeric>
//#include <bits/stdc++.h>
#include<cstring>
#include<iostream>
#include<functional>
using namespace std;
int main() {

	int r, g, b; //X, A, B;

	cin >> r >> g >> b;// X >> A >> B;

	int num = r * 100 + g * 10 + b;
	if (num % 4 == 0)
		cout << "YES\n";
	else
		cout << "NO\n";

	cin >> r;
	return 0;
}
