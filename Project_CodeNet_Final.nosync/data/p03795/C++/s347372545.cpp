#include<iostream>
using namespace std;
int main(){
	int n;
	int total=0;
	int discount=0;
	int payment =0;
	cin>>n;
	total=n*800;
	discount=(n/15)*200;
	payment=total-discount;
	cout<<payment;
	return 0;
}