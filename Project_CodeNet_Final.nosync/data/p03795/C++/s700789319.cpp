#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int x=N*800;
	int y;
	y=200;
 if(N>=15){
	y*=(N/15);
	cout<<x-y;
		}
	else if(N<15){
	cout<<x;	}
	return 0;
}