#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>


using namespace std;
int main(){
	int N;
	cin>>N;
	for(int II=0;II<N;II++){
	long long int AA;
	cin>>AA;
	int YY;
	cin>>YY;

	int N2;
	cin>>N2;
	long long int max=0;
	for(int I=0;I<N2;I++)
	{
		long long int A,B=0;
		A=AA;
		int s;
		int K;
		double R;
		
		cin>>s>>R>>K;
		if(s==0){
			for(int i=0;i<YY;i++)
			{B+=A*R;A-=K;}
			if(max<A+B)max=A+B;
		}
		else{
			for(int i=0;i<YY;i++)
			{A+=A*R;A-=K;}//cout<<A<<endl;}
			if(max<A)max=A;
		}
	}
		cout<<max<<endl;
	}
	return 0;
}