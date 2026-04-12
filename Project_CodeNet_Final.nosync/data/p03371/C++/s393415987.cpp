#include<bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
	int min=2000000000;
  	int p;
	for(int i=0;i<=max(X,Y)*2;i+=2){
		p=C*i;
		p+=max(0,X-i/2)*A;
		p+=max(0,Y-i/2)*B;
		if(p<min)min=p;
	}
	cout<<min<<endl;
	return 0;
}