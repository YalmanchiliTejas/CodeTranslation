#include <bits/stdc++.h>

#define INF 1 << 29
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)

using namespace std;

typedef pair<int,int> pii;
typedef long long int ll;

void gen_sosuu(int sosuu[]){
  REP(i,100010){
    sosuu[i] = true;
  }
  sosuu[0] = false;
  sosuu[1] = false;
  sosuu[2] = true;
  FOR(i,2,sqrt(100000)+1){
    if(sosuu[i] == false) continue;
    for(int j = 2; i*j<=100000;j++){
      //printf("%d %d %d\n",i*j,i,j);
      sosuu[i*j] =false;
    }
  }
}

int n;

char init[3] = "SW";
char ans[100010];
char   s[100010];

char another(char s){
  if(s=='S') return 'W';
  return 'S';
}

char flip_s(char s){
  if(s=='o') return 'x';
  return 'o';
}


int main(){
  scanf("%d",&n);
  scanf("%s",s);
  s[n] = s[0];
  s[n+1] = s[1];
  char now,prev;
  REP(i1,2)REP(i2,2){
    prev = init[i1];
    now = init[i2];
    ans[0] = prev;
    ans[1] = now;
    char tmp;
    FOR(i,1,n+2){
      char q = s[i];
      if(now == 'W') q = flip_s(q);
      if(q == 'o'){
        ans[i+1] = ans[i-1];
      }else{
        ans[i+1]= another(ans[i-1]);
      }
      now = ans[i+1];
      prev = ans[i];
    }
    //printf("%s %c\n",ans,tmp);
    if(ans[0] == ans[n] && ans[1] == ans[n+1]){
      ans[n] = '\0';
      printf("%s\n",ans);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
