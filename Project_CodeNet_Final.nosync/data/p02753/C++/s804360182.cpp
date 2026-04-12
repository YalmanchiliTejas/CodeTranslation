#include<bits/stdc++.h>
using namespace std;
#define forr(x,n) for(int x = 0; x < n; ++x)
#define pr pair<int,int>
#define ll long long int
const int mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
	int a=0,b=0;
	forr(i,s.length())
	{
		if(s[i]=='A')
		a++;
		else
		b++;
	}
	if(a>0&&b>0)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}


