#define _CRT_SECURE_NO_WARNINGS
#define lp(i,n) for(int i=0;i<n;i++)
#include<bits/stdc++.h>

using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}
