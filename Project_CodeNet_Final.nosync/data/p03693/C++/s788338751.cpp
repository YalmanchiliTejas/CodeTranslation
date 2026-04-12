#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)

int main(){
	int r,g,b;
	cin >> r >> g >> b;
	if((g*10+b) % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
