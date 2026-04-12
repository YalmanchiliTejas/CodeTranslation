#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
#define FOR(i, o, n) for (auto i = (o); (i) < (n); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (auto i = (n)-1; (i) >= 0; --i)
#define REPI(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define REPIR(itr, v) for (auto itr = v.rbegin(); itr != v.rend(); ++itr)
#define fi first
#define se second
#define ll long long
#define V2(name, h, w) vector<vector<int> > name((h), vector<int>(w));
int main(){
	char c; cin >> c;
	if(c=='a' or c=='e' or c=='i' or  c=='o' or c=='u') cout << "vowel" << endl; 
	else cout << "consonant" << endl;
}
