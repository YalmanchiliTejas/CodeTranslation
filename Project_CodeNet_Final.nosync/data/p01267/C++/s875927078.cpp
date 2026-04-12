#include <iostream>

using namespace std;

int main()
{
	for(int n,a,b,c,x;cin>>n>>a>>b>>c>>x,n|a|b|c|x;){
		int y[n];
		for(int i=0;i<n;i++)
			cin>>y[i];
		
		int i=0,t=0;
		for(;t<=10000;t++){
			if(x==y[i])
				i++;
			if(i==n)
				break;
			x=(a*x+b)%c;
		}
		
		if(i==n)
			cout<<t<<endl;
		else
			cout<<-1<<endl;
	}
	
	return 0;
}