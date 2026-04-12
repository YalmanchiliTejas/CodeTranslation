#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y;

int main()
{
	cin>>a>>b>>c>>x>>y;
	int ans=a*x+b*y,a1=x,b1=y,c1=0;
    while (1)
        {        	
		    int ans1=ans+2*c;
			if (a1>0) {a1--;ans1-=a;}
			if (b1>0) {b1--;ans1-=b;}
			if (a1==0&&b1==0) {if (ans1<ans) ans=ans1;break; } 
        	if (ans1>=ans) break;
        	ans=ans1;
		}
	cout<<ans;
	return 0;
}