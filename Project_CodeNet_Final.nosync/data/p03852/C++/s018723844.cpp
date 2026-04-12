#include <bits/stdc++.h>
#define rep(x, y) for(int x = 0; x < (y); x++)
#define REP(x, z, y) for(int x = (z); x < (y); x++)
#define all(x) x.begin(), x.end()
#define len(x) (sizeof(x) / sizeof(x[0]))
#define split_str(str, sp_word) istringstream stream(str); string res; for(int cnt = 0; getline(stream,res,sp_word); cnt++)
#define scanln(x) fgets(x, sizeof x, stdin)
#define down_queue(x) priority_queue<x>
#define up_queue(x) priority_queue<x, vector<x>, greater<x>>
#define i_str(x) atoi(x.c_str())
#define digit(x) ((int)log10((double)(x)) + 1)
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
using namespace std;
const int MOD = 1000000007; 
typedef long long ll;
typedef string str;
 
int main(){
  char c;
  cin >> c;
  str vowels = "aiueo";
  for(int i : vowels){
    if(c == i) {
      printf("vowel");
      return 0;
    }
  }
  printf("consonant");
  return 0;
}