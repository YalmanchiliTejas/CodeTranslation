#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

void Main()
{
	int n;
  	cin >> n;
  	vector<string> s(n);
	vi temp(26,100);

  	rep(i,n) {
      cin >> s[i];
      vi cnt(26,0);
      rep(j,s[i].size()) cnt[s[i][j]-'a']++;
      rep(j,26) temp[j] = min(temp[j], cnt[j]);
    }
  
  	rep(i,26){
    	rep(j,temp[i]) cout << (char)('a'+i);
    }
	return;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}