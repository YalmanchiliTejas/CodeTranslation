#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<vector>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;

int main(void) {
	int r, g, b;
	cin >> r >> g >> b;
	if((100*r+10*g+b)%4==0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}