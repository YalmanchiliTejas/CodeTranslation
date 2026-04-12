#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<complex>
using namespace std;
typedef long long int llint;
int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int x = a * 100 + b * 10 + c;
	if (x % 4 == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}
