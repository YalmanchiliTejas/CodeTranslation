#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int b[27]={0},flag = 0;
	while(n--)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
		if(!flag)
		{
			for(auto it:s)
				b[it-'a']++;
		}
		else
		{
			int a[27]={0};
			for(auto it:s)
				a[it-'a']++;
			for(int i = 0;i<27; i++)
				b[i] = min(b[i],a[i]);
		}
		flag = 1;
	}
	for(int i = 0;i<27 ; i++)
		for(int j = 1; j<=b[i]; j++)
		{
			char ch = 'a'+i;
			cout<<ch;
		}
	return 0;
}