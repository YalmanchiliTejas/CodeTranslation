#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a,b,c;
	cin>>a>>b>>c;
	int sum=(a*100+b*10+c);
	if(sum%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
