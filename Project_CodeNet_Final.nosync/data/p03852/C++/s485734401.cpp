#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
char c;
cin >> c;
if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') {
  cout << "vowel" << endl;
} else {
  cout << "consonant" << endl;
}
return 0;
}
