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
  ll h, w, c=0;
  cin >> h >> w;
  string s;
  forll(i, 0, h){
	cin >> s;
	forll(i, 0, w){
	  if (s[i] == '#')
		c++;
	}
  }
  if (c > (h + w - 1))
	cout << "Impossible" << endl;
  else
	cout << "Possible" << endl;
}

