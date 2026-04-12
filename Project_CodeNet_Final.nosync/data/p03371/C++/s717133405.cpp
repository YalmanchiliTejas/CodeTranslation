#include<iostream>

using namespace std;

int A,B,C,X,Y;
int ans=0;

int main(){
	cin>>A>>B>>C>>X>>Y;
	
	int a=C;
	int b=C;

	if(A-a+B-b<=0){
		cout<<A*X+B*Y<<endl;
		return 0;
	}else{


	if(A>C*2){
		ans+=C*2*X;
		Y-=X;
		X=0;
		if(Y<0)Y=0;
	}
	if(B>C*2){
		ans+=C*2*Y;
		X-=Y;
		Y=0;
		if(X<0)X=0;
	}
	if(Y==0){
		cout<<ans+X*A<<endl;
		return 0;
	}
	if(X==0){
		cout<<ans+Y*B<<endl;
		return 0;
	}
	}

	
		int ma=max(X,Y);
		int mi=min(X,Y);
		ans+=mi*C*2;


		
		if(X<Y)ans+=B*(ma-mi);
		else if(X>Y)ans+=A*(ma-mi);


	cout<<ans<<endl;

	
	return 0;
}



