#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,ab,x,y,ans[3];
	cin >> a >> b >> ab >> x >> y;
	
	ans[0] = a*x + b*y;
	if(x >= y)
		ans[1] = y*2*ab + (x-y)*a;
	
	else
		ans[1] = x*2*ab + (y-x)*b;
		
	ans[2] = max(x,y)*2*ab;
		
	cout << min(ans[0],min(ans[2],ans[1])) << endl;
	return 0;
}
