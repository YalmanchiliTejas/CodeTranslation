#include <bits/stdc++.h>
using namespace std;

	int n,sum,a;
int main(){
	cin >> n;
	sum= n*800;
	while (n>=15){
		n-=15;
		a++;
	}
	a*=200;
	cout << sum-a << endl;
}