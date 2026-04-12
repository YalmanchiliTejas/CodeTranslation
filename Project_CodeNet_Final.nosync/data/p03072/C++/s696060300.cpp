#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+7;
int N[maxn];
int main()
{
	int n;cin>>n;int maxx=0;int cnt=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&N[i]);
		if(N[i]>=maxx) cnt++;
		maxx=max(N[i],maxx);
	}
	cout<<cnt<<endl;
}
