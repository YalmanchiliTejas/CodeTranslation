#include <bits/stdc++.h>
using ll = long long;
using namespace std;

signed
main(){
	int n;
	cin >> n;
	vector<string> s(n);

	for(int i=0;i<n;i++)
	{
			cin >> s[i];
	}

	//アルファベット配列
	vector<vector<int> > al(26, vector<int>(n, 0));

	for(int i=0;i<n;i++)
	{
			for(int j=0;j<s[i].size();j++)
			{
					al[s[i][j]-'a'][i]++;
			}
	}

	string ans = "";
	for(int i=0;i<26;i++)
	{
			sort(al[i].begin(),al[i].end());
			ans += string(al[i][0], char('a'+i));
	}

	cout << ans << endl;
}