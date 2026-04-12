#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

int main()
{

	ios_base:: sync_with_stdio(false); cin.tie(0);
	int n,k;
	cin>>n;
	string s;
	cin>>s;
	cin>>k;
	char c=s[k-1];

	for(int i=0; i<n; i++) {
		if(s[i]!=c) {
			s[i]='*';
		}
	}
	cout<<s<<endl;

	return 0;
}
