#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <string.h>
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
typedef long long ll;
using namespace std;

int main(){
  int N;
  scanf("%d",&N);
  getchar();

  int INF = 51;
  int a[26],cnt_line[26] = {};
  fill(a,a + 26,INF);

  string line;
  rep(i,N){
    getline(cin,line);

    for(char c:line) 
      a[c - 'a'] = min(a[c - 'a'], (int)count(all(line), c)); 

    for(int i = 'a'; i <= 'z'; i++)
      if(count(all(line), i) > 0)
        cnt_line[i - 'a']++;
  }

  rep(i,26)
    if(cnt_line[i] >= N && a[i] != INF)
      rep(j,a[i]) 
        printf("%c",i + 'a');

  return 0;
}