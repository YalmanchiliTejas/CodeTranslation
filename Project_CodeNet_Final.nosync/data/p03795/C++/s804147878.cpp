#include<iostream>
using namespace std;
int main(){
	int N,x=200;
	cin>>N;
	if(N<15)
	cout<<N*800<<endl;
	else if(N==15)
	cout<<(N*800)-200;
	else
	cout<<(N*800)-(x*(N/15));
}