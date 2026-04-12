#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int main() {
	int A,B,C,X,Y,sum=0,ans=1000000000;
	cin>>A>>B>>C>>X>>Y;
	for(int i=0;i<max(X,Y)+1;i++)
	{
		sum+=(i*C*2);
		if(X>i)sum+=((X-i)*A);
		if(Y>i)sum+=((Y-i)*B);
		ans=min(sum,ans);
		//cout<<sum<<endl;
		sum=0;
	}
	cout<<ans;
	}