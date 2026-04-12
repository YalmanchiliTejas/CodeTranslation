#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);	
	int r,g,b;
	cin>>r>>g>>b;
	int sum = r*100+g*10+b;
	if(sum%4==0)
		cout<<"YES";
	else
		cout<<"NO";
    return 0;
}