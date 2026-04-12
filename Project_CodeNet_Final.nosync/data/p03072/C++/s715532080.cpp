#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{
	int n,a,m,sum=1;
	cin>>n;
	cin>>a;
	m=a;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		if(a>=m)sum++;
		m=max(m,a);
	}
	cout<<sum<<endl;
	return 0;
}