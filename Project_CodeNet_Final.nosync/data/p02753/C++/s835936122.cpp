#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main()
{
	int a=0,b=0;
	string s;
	cin>>s;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='A')a=1;
		if(s[i]=='B')b=1;
	}
	if(a==1&&b==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}