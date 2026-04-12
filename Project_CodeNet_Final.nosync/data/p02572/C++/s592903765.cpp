#include<bits/stdc++.h>
using namespace std;
long long a[200001];

void write_128(__int128 a) 

{

    if(a < 0) putchar('-'), a *= -1;

    if(a >= 10) write_128(a / 10);

    putchar(a % 10 + '0');

}
int main()
{
	int n;
	cin>>n;
    __int128 sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
		ans+=a[i]*(sum-a[i]);
	write_128((ans/2)%(unsigned long long)1000000007);
	return 0;
}