#include <bits/stdc++.h>
#define pb push_back
#define sz(a) int(a.size())
#define re return
using namespace std;
int main()
{
	char a,b,c;
	cin>>a>>b>>c;
	if (a==b && b==c)  cout<<"No";
	else if (a==b || b==c || a==c)  cout<<"Yes";
	else  cout<<"No";
	re 0;
}