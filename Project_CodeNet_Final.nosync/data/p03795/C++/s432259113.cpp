#include <iostream>
using namespace std;

int main() {
	int n;
	int discount=0;
	int paid=0;
	cin>>n;
	paid = n*800;	
	while(n-15>=0){
		n=n-15;
		discount = discount + 200;
	}
	paid = paid - discount;
	cout<<paid<<endl;
	return 0;
}