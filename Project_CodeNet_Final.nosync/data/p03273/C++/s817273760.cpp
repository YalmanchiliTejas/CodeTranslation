#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll h, w;
  cin >> h >> w;
  vector <string> s;
  string t;
  forll(i, 0, h){
	cin >> t;
	if (t.find('#') == string::npos)
	  continue;
	s.push_back(t);
  }
  for (int i=w-1; i>=0; i--){
	bool r = true;
	forll(j, 0, s.size()){
	  if (s[j][i] == '#'){
		r= false;
		break;
	  }
	}
	if (r == true){
	  forll(j, 0, s.size()){
		s[j].erase(s[j].begin() + i);
	  }
	}
  }
  forll(i, 0, s.size())
	cout << s[i] << endl;
}
