#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n; cin >> n;
   	vector<string> s(n);
  	for(int i=0; i<n; i++) cin >> s[i];
                                    
   vector<multiset<char> > sset(n);
    for(int i=0; i<n; i++) {
      for(auto x : s[i]) {
        sset[i].insert(x);
      }
    }
	multiset<char> ans; 
 	set<char> tmp;
  for(auto x:sset[0] ) tmp.insert(x);
  	for(auto x : tmp) {
      int f = sset[0].count(x);
      for(int i=1;i<n; i++) 
        f = min((int)sset[i].count(x),f);
      for(int i=0;i<f;i++)
        ans.insert(x);
    }
	for(auto x : ans) cout << x;
  	cout << endl;
}