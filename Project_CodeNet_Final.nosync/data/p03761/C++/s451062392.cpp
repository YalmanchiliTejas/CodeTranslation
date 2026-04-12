#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll n;
  cin >> n;
  string s, t="";
  vecll m(26, LLONG_MAX);
  forll(i, 0, n){
	cin >> s;
	vecll a(26, 0);

	forll(j, 0, s.size()){
	  a[s[j] - 'a'] += 1;
	}
	forll(j, 0, 26){
	  m[j] = min(a[j], m[j]);
	}
  }
  forll(j, 0, 26){
	if (m[j] == LLONG_MAX)
	  m[j] = 0;
	t += string(m[j], (char)('a' + j));
  }
  cout << t << endl;
}
