#include<bits/stdc++.h>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
const int MOD = 1000000007;

int main()
{
  int A,B;
  char s;
  cin >> s;
  set<char> d;
  d.insert('a');
  d.insert('i');
  d.insert('u');
  d.insert('e');
  d.insert('o');
  cout << (d.count(s)==0 ? "consonant" : "vowel") << endl;
  return 0;
}

