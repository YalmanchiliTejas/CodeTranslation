#include<cstdio>

#define t(a) ((a == 'S') ? (0) : (1))

using namespace std;

int N;
char S[100001];
char ans[100001];
char sw[3] = "SW";
bool f1 = true;

char dp(short int b, short int t, char r);

int main(){

  scanf("%d", &N);
  scanf("%s", S);

  for(int l = 0; l < 4 && f1; l++){
    ans[0] = sw[l/2];//ssww
    ans[1] = sw[l%2];//swsw
    for(int m = 1; m < N && f1; m++){
      if(m < N-1 ){
        ans[m+1] = dp(t(ans[m-1]), t(ans[m]), S[m]);//1 <= m <= N-2, ans[N-1]まで求める
      }else if(ans[0] == dp(t(ans[N-2]), t(ans[N-1]), S[N-1])){//m = N-1, ans[0]に入るべき値を確認
        if(ans[1] == dp(t(ans[N-1]), t(ans[0]), S[0])){
          f1 = false;
        }
      }
    }
  }

  if(f1){
    printf("-1");
  }else{
    /*
    for(int i = 0; i < N; i++){
      printf("%c", ans[i]);
    }
    */
    
    ans[N] = '\0';
    printf("%s", ans);
    
  }

  return 0;

}

char dp(short int b, short int t, char r){

  if((b+t)%2 == 0){
    if(r == 'o'){
      return 'S';
    }else{//r == 'x'
      return 'W';
    }
  }else{//(a+b)%2 == 1
    if(r == 'o'){
      return 'W';
    }else{//r == 'x'
      return 'S';
    }
  }

  /*
  if( b == 's' && t == 's' && r == 'o') return 's';
  if( b == 's' && t == 'w' && r == 'o') return 'w';
  if( b == 'w' && t == 's' && r == 'o') return 'w';
  if( b == 'w' && t == 'w' && r == 'o') return 's';
  if( b == 'w' && t == 'w' && r == 'x') return 'w';
  if( b == 'w' && t == 's' && r == 'x') return 's';
  if( b == 's' && t == 'w' && r == 'x') return 's';
  if( b == 's' && t == 's' && r == 'x') return 'w';
  */
  return '\0';

}
