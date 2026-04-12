#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	long long int a[200001],b[200002],z=0;
	b[0]=0;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i+1]=(b[i]+a[i])%(1000000007);
    }
    for(int i=1;i<n;i++)
    {
        z=(z+b[i]*a[i])%(1000000007);
    }
    cout<<z<<endl;
	return 0;
}
