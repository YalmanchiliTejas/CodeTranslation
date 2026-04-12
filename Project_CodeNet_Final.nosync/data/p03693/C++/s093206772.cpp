#include<iostream>
using namespace std;
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int r,g,b,total;
 
	cin >> r >> g >> b;
	r = r *100;
	g = g*10;
	total= r+g+b;
	
	if (total% 4== 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
	return 0;
}