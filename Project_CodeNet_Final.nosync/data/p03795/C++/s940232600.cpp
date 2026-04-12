#include<iostream>
using namespace std;
int main(){
	int n,x=200;
	cin>>n;
	if(n<15){
		cout<<n*800<<endl;
	}
	else if(n==15)
	cout<<(n*800)-200;
	else
	cout<<(n*800)-(x*(n/15));
}