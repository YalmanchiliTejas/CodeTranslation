#include<bits/stdc++.h>
using namespace std;
int a,b,c,m,n,sum=0;
int main()
{
	cin>>a>>b>>c>>m>>n;
	int k,l;
	l=min(m,n);
	k=max(m,n);
	if(c<(a+b)/2) 
	  {
	    sum+=2*c*l;
	    if(m>n) sum+=(m-n)*a;
	      else sum+=(n-m)*b;
	  }
	  else sum=a*m+b*n;
	if(c*2*k<sum) sum=c*2*k;
	cout<<sum<<endl;
	return 0;
}