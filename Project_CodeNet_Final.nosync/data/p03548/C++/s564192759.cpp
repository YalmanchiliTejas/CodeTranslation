#include<iostream>
using namespace std;

int main(){
	int X,Y,Z;
	cin>>X>>Y>>Z;
	int res;
	for(res=0;;){
		if(X-Z>=Y+Z){
			X-=Y+Z;
			res++;
		}else{
			break;
		}
	}
	cout<<res<<endl;
}
