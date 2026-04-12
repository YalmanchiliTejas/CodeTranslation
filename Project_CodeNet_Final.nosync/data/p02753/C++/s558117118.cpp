#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pb push_back
#define x first
#define y second
#define pii pair<int,int>

const int mod = 1e9+7;

int main()
{
	IOS
	string s;
	cin>>s;
	int cnt[2]={0,0};
	int i;
	for(i=0;i<3;i++)
		cnt[s[i]-'A']++;
	if(cnt[0] && cnt[1])
		cout<<"Yes";
	else
		cout<<"No";
}
