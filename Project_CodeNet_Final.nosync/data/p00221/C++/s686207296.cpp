#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

#define rep(i, j) FOR(i, 0, j)
#define FOR(i, j, k) for(int i = j; i < k; ++i)

using namespace std;

int main(){
  int m, n;
  char s[9];
  while(scanf("%d%d", &m, &n) && m && n){
      vector<bool>mem(m);
      rep(i, m) mem[i] = false;
      int p = 0, c = 1;
      FOR(i, 1, n+1){
	scanf("%s", s);
	if(c < m){
	  int f = 0;
	  if(i % 15 == 0){
	    if(strcmp(s, "FizzBuzz")) f = 1;
	  }else if(i % 5 == 0){
	    if(strcmp(s, "Buzz")) f = 1;
	  }else if(i % 3 == 0){
	    if(strcmp(s, "Fizz")) f = 1;
	  }else{
	    if(i != atoi(s)) f = 1;
	  }
	
	  if(f) mem[p] = 1, ++c;
	  do{
	    p = (p+1)%m;
	  }while(mem[p]);
	}
      }
      int f = 0;
      rep(i, m){
	if(!mem[i]){
	  printf(f ? " %d":"%d", i + 1);
	  f = 1;
	}
      }
      puts("");
  }
  return 0;
}