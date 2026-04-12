#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#define FOR(x, z, y) for(int x = (z); y; x++)
#define rep(x, y) for(int x = 0; x < (y); x++)
#define all(x) x.begin(), x.end()
#define len(x) (sizeof(x) / sizeof(x[0]))
#define split_str(str, sp_word) istringstream stream(str); string res; while(getline(stream,res,sp_word))
#define rem_space(x) x.erase(remove(all(x), ' '),x.end())
#define scl(x) fgets(x, sizeof x, stdin)
#define down_queue(x) priority_queue<x>
#define up_queue(x) priority_queue<x, vector<x>, greater<x>>
#define i_str(x) atoi(x.c_str())
typedef long long ll;
using namespace std;

int main(){
  string rgb;
  getline(cin,rgb);
  rem_space(rgb);

  if(i_str(rgb) % 4 == 0) puts("YES");
  else puts("NO");

  return 0;
}