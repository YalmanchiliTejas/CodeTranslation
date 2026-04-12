#include<bits/stdc++.h>
using namespace std; 

//int _; 

int r,g,b;
 
int main()
{
	//for(scanf("%d",&_);_;_--)
	cin >> r >> g >> b;
	cout << ((g*10+b)%4 ? "NO\n":"YES\n");
	return 0;
}

