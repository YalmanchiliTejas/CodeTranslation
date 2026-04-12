#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	c=c*2;
	int ans=0;
	if(a+b<=c)
		ans=a*x+b*y;
	else if(c<=a and c<=b)
		ans=c*max(x,y);
	else if(c<=a)
		ans=c*x+max(0,y-x)*b;
	else if(c<=b)
		ans=c*y+max(0,x-y)*a;
	else
		ans=c*min(x,y)+a*(x-min(x,y))+b*(y-min(x,y));
	

	cout << ans << endl;




	
}