#include<bits/stdc++.h>
using namespace std;
const int pi=3.1415926535897932384626433832795;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(1e9+7)
#define pb push_back
#define mp make_pair
int n;
string s;
bool res[100005];
int main()
{
	cin>>n>>s;
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++)
		{
			res[0]=a;
			res[1]=b;
			for(int j=2;j<n;j++)
				res[j]=((s[j-1]!='o')^res[j-1])^res[j-2];
			bool flag=1;
			for(int x=0;x<n;x++)
			{
				int pr=(x-1+n)%n;
				int nx=(x+1+n)%n;
				if(((s[x]=='o')^res[x])!=(res[pr]==res[nx]))
					flag=0;
			}
			if(flag)
			{
				for(int j=0;j<n;j++)
					cout<<(!res[j]?'S':'W');
				return 0;
			}
		}
	puts("-1");
	return 0;
}