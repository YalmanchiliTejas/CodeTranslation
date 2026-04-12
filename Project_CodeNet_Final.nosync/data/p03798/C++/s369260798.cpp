#include<cstdio>

#define t(a) ((a == 'S') ? (0) : (1))

using namespace std;

int N;
char S[100001];
char ans[100001];
char sw[3] = "SW";
bool f1 = true;

char dp(short int b, short int t, char r)
{

  if((b+t)%2 == 0){
    if(r == 'o'){
      return 'S';
    }else{
      return 'W';
    }
  }else{
    if(r == 'o'){
      return 'W';
    }else{
      return 'S';
    }
  }
  return '\0';

}

int main(){

  scanf("%d", &N);
  scanf("%s", S);

  for(int l = 0; l < 4 && f1; l++){
    ans[0] = sw[l/2];
    ans[1] = sw[l%2];
    for(int m = 1; m < N && f1; m++){
      if(m < N-1 ){
        ans[m+1] = dp(t(ans[m-1]), t(ans[m]), S[m]);
      }else if(ans[0] == dp(t(ans[N-2]), t(ans[N-1]), S[N-1])){
        if(ans[1] == dp(t(ans[N-1]), t(ans[0]), S[0])){
          f1 = false;
        }
      }
    }
  }

  if(f1)
  {
    printf("-1");
  }
  else
  {
    ans[N] = '\0';
    printf("%s", ans);

  }
  return 0;
}
