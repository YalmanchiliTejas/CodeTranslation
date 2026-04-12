#include<bits/stdc++.h>
using namespace std;
long long A[1000000],cums[1000000];
map <long long ,long long > a;
vector <long long> v;
long long M=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n,i,j,k,x,y,z;
    cin>>n;
    x=0;
    for (i=0;i<n;i++)
    {
    	cin>>A[i];
    	x=(x+A[i])%M;
	}
	cums[n-1]=A[n-1];
	for (i=(n-2);i>=0;i--)
	{
		cums[i]=(cums[i+1]+A[i])%M;
	}
	z=0;
	for (i=0;i<n;i++)
	{
		z=(z+(cums[i+1]*A[i])%M)%M;
	}
	cout<<z<<endl;
}