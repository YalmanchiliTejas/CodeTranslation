#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int r,g,b;
int ans;

int main()
{
	cin >> r >> g >> b;
	ans += (g * 10 )+ b;
	
	if(ans % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	
	
	return 0;
}