#include<iostream>
#include<complex>
#include<algorithm>
#include<queue>
#include<cstdio>
#define rep(i, n) for (int i = 0; i < int(n); ++i)

using namespace std;

int main(void){

	int a,b;
	cin >> a >> b;
	if(a > b)
	{
		cout << "a > b" << endl;
	}else if(a < b)
	{
		cout << "a < b" << endl;
	}else{
		cout << "a == b" << endl;
	}

	return 0;
}