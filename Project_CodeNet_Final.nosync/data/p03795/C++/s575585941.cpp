#include<bits/stdc++.h>
#define FOR(x, z, y) for(int x = (z); y; x++)
#define rep(x, y) for(int x = 0; x < (y); x++)
#define REP(x, z, y) for(int x = (z); x < (y); x++)
#define all(x) x.begin(), x.end()
#define len(x) (sizeof(x) / sizeof(x[0]))
#define split_str(str, sp_word) istringstream stream(str); string res; FOR(cnt, 0, getline(stream,res,sp_word))
#define scanln(x) fgets(x, sizeof x, stdin)
#define down_queue(x) priority_queue<x>
#define up_queue(x) priority_queue<x, vector<x>, greater<x>>
#define i_str(x) atoi(x.c_str())
#define digit(x) ((int)log10((double)(x)) + 1)
typedef long long ll;
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  printf("%d",(N * 800) - ((N / 15) * 200)); 
  return 0;
}