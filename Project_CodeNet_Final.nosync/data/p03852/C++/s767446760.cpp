#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(LL i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  char c;
  cin >> c;
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    cout << "vowel";
  }
  else{
    cout << "consonant" << endl;
  }
  
  return 0;
}
