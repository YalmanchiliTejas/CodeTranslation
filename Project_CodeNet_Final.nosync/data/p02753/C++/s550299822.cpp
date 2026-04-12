#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ll long long int
#define ld long double
#define tc long long t;cin>>t;while(t--)
#define E endl
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define V vector<ll>vect;
using namespace std;
int main()
{
string s;
cin>>s;
ll flag=0,flag1=0;
for(ll i=0;i<s.length();i++)
{
	if(s[i]=='A')
	{
		flag=1;
	}
		if(s[i]=='B')
	{
		flag1=1;
	}

}
if(flag&&flag1)
cout<<"Yes";
else
cout<<"No";
return 0;
}

