#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}