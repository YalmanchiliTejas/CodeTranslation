#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[30] ;
int main()
{

	memset(dp,100,sizeof dp);
	int n;
	cin >> n;
	vector<string>v;
    for(int i=1; i<=n; i++)
    {
        map<char,int>mp;
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        for(char cc = 'a'; cc<='z'; cc++)
        {
            dp[cc-'a'] = min(dp[cc-'a'],mp[cc]);
        }

    }
    string ans = "" ;
    for(char c = 'a' ; c<='z' ; c++)
    {
        if(dp[c-'a'])
        {
            int kk = dp[c-'a'];
            while(kk--)ans+=c;
        }
    }
    cout << ans << endl;


}
