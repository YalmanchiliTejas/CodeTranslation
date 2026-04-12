#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long int

int main(int argc, const char * argv[]) {
	int N;
	cin >> N;
	if(N==3 || N==5 || N==7){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
