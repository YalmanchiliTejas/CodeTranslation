#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int cnt=0;
	int ans=0;
	long long mod=(1e+9)+7;
	long long n;
	cin>>n;
	vector<string> s(n);
	string t;
	t.clear();

	for(int i=0;i<n;i++) cin>>s[i];

	for(char c='a';c<'z'+1;c++){
		int cc=INT_MAX;

		for(int i=0;i<n;i++){
			cnt=0;
			for(int j=0;j<s[i].size();j++)
				if(s[i][j]==c)cnt++;
			cc=min(cc,cnt);
		}
		if(cc!=INT_MAX)
			for(int i=0;i<cc;i++) t+=c;
	}
	cout<<t<<endl;
}