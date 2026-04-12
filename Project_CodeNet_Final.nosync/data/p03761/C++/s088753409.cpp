#pragma GCC optimize ("Ofast","unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define F first
#define S second
#define setpre(a) cout.precision(a),cout<<fixed;
#define ALL(a) a.begin(),a.end()
#define MEM(a,b) memset(a,b,sizeof a)
#define Tie ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF=1e9;
int n,cnt[26],ans[26];
string s;

int main()
{
	cin>>n;
	for(int i=0;i<26;i++)
		ans[i]=INF;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		MEM(cnt,0);
		for(char j:s)
			cnt[j-'a']++;
		for(int j=0;j<26;j++)
			ans[j]=min(ans[j],cnt[j]);
	}
	for(int i=0;i<26;i++)
		for(int j=0;j<ans[i];j++)
			cout << char(i+'a');
	cout <<'\n';
}
