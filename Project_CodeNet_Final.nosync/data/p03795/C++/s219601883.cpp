#include<iostream>
using namespace std;
int main(){
	int n,x,y;
	cin>>n;
	if(n>=1&&n<=100){
		x=800*n;
		y=x-(n/15)*200;
		}
		cout<<y;
	}