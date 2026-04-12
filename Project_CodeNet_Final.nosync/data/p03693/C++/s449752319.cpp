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
	string a="";
	char c;
	cin>>c;
	a += c;
	cin>>c;
	a += c;
	cin>>c;
	a += c;
	int y = stoi(a);
	if(y%4==0)
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}