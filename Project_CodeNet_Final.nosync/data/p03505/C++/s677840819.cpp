#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	ll k,a,b;
	cin>>k>>a>>b;
	if(a>=k)
		puts("1");
	else if(a-b<=0)
		puts("-1");
	else {
		ll ans=(k-a)/(a-b);
		if((k-a)%(a-b)!=0)
			ans++;
		cout<<(ans*2+1)<<endl;
	}
		
	return 0;
}