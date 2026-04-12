#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define POW(n) ((n)*(n))
#define ALL(a) (a).begin(),(a).end()
#define cerr if(false) cerr
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<unsigned long long> vull;

string ans = "aiueo";

void solve(string c){
	REP(i,5){
    if(c[0] == ans[i]){
      cout << "vowel" << endl; return;
    }
  }
  cout << "consonant" << endl;
}



int main(){	
	ios::sync_with_stdio(false);
	string c;
	cin >> c;
	solve(c);
	return 0;
}
