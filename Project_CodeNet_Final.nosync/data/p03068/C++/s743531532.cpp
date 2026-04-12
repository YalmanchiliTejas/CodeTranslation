#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k; string s; cin>>n>>s>>k;
	for (int i=0; i<n; i++)
		if(s[i]!=s[k-1])
			s[i]='*';
	cout<<s<<"\n";
	return 0;
}