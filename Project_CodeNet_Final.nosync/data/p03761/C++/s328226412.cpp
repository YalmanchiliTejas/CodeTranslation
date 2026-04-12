#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ll long long int
#define inf 1450000090
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sdl(x) scanf("%lld",&x)
#define nax 100010
#define mp make_pair
#define sz(x) (int)(x.size())
#define pl pair <ll , ll>
#define pii pair < int , pair <int ,int > >
#define MOD 1000000007
using namespace std;
int arr[55][30];
int main(int argc, char const *argv[])
{
  //freopen("input.txt","read",stdin);
  //freopen("output.txt","write",stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
  	string str;
  	cin >> str;
  	int l = str.length();
  	for (int j = 0; j < l; ++j)
  	{
  		arr[i][str[j]-'a']++;
  	}
  }
  string ans = "";
  for (int i = 0; i < 26; ++i)
  {
  		int mi = 1000000;
  		for (int j = 0; j < n; ++j)
  		{
  			mi = min(mi,arr[j][i]);
  		}
  		for (int j = 0; j < mi; ++j)
  		{
  			ans+=(char)('a'+i);
  		}
  }
  cout << ans << '\n';
  return 0;
}