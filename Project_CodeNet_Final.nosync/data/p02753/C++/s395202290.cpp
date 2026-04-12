#include<bits/stdc++.h>
#define mx 100000
#define pb push_back
#define siz(v) v.size();
#define print(a) printf("%d",a)
#define sc1(a) scanf("%d",&a)
using namespace std;

typedef unsigned long  ull;
typedef long long int lli;

int main()
{
 	ios_base::sync_with_stdio(0);
 	cin.tie(0);
	
	string s;
	cin>>s;
	
	int a=0,b=0;
	for(int i=0;i<3;++i)
	{
		if (s[i]=='A') ++a;
		else ++b;
	}	
	if (a==3 || b==3) cout<<"No\n";
	else cout<<"Yes\n";
		

 return 0;
 }
