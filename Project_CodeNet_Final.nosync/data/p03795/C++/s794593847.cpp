#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

#define rep(i, n) for(int i=0;i<n;i++)

using namespace std;
int main(){
	int n;
	cin >> n;

	cout << (800 * n) - (n / 15) * 200 << endl;

	return 0;
}