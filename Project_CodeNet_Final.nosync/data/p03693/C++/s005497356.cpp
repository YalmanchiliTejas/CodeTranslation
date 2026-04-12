#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,word;
	cin>>a>>b>>c;
	word=a*100+b*10+c;
	if(word%4==0)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}