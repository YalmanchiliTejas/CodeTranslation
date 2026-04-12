#include<iostream>
using namespace std;

int main(){
	int sum,n;

	cin >>n;
	sum=n*800;
	sum-=(n/15)*200;

	cout << sum << endl;
	return 0;
}