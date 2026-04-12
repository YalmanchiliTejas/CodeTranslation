#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
string a;
signed main()
{
	cin>>a;
	rep(i,a.size()-1){
		if(a[i]=='A'&&a[i+1]=='C'){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}