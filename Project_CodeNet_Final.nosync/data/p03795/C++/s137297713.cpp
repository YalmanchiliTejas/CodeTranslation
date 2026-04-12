#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
 
using namespace std;
 
int main() {
	int N;
	cin >> N;
	long long back = ceil(N/15) *200;
	long long price = N*800 - back;
	cout << price << endl;
	
	return 0;
}