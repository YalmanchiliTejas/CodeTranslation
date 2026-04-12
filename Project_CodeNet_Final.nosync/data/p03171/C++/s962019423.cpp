#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N =3e3+20;

ll a[N],f[N][N];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i][i]=a[i];	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j+i-1<=n;j++)
		{
			f[j][j+i-1]=max(a[j]-f[j+1][j+i-1],a[j+i-1]-f[j][j+i-2]);
		}
	}
	cout<<f[1][n]<<endl;
}