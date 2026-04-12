#include<iostream>
using namespace std;

int main() {
	int x,y;
	cin>>x>>y;
	if(x<y){
		cout<<"a < b"<<endl;
		return 0;
	}else if(x>y){
		cout<<"a > b"<<endl;
		return 0;
	}else if(x==y){
		cout<<"a == b"<<endl;
		return 0;
	}else{
		return 1;
	}
}