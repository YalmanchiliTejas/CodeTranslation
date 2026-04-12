#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a,b,c;
	cin>>a>>b>>c;
	a=b*10+c;
	if(a%4==0)
		cout<<"YES";
	else
		cout<<"NO";
	
    return 0;
}