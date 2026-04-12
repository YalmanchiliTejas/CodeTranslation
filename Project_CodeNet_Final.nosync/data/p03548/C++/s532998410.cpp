#include <bits/stdc++.h>
using namespace std;

long long len,a,dis,ans;

int main()
{
	cin>>len>>a>>dis;
    if (len%(a+dis)>=dis)  ans=len/(a+dis);
    else ans=(len/(a+dis))-1;
    cout<<ans<<endl;
	return 0;
}