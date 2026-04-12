#include <bits/stdc++.h>
using namespace std;
int a,b,c,x,y,sum1,sum2,sum3,sum;
int main() {
	cin>>a>>b>>c>>x>>y;
	
	sum1=a*x+b*y;
	
	sum2+=min(x,y)*c*2;
	if(x>=y)sum2+=(x-y)*a;
	else if(x<y)sum2+=(y-x)*b;
	
	sum3=max(x,y)*c*2;
	
	
	
	sum=min(sum1,sum2);
	sum=min(sum,sum3);
	cout<<sum<<endl;
}