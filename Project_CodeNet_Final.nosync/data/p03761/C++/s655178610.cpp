#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n;
  int i,j,k,l;
  char s[56][56];
  int cnt[56][28];
  int out[28];
  scanf("%d", &n);

  for(i = 0;i < n;i++) scanf("%s", s[i]);

  for(i = 0;i <= 26;i++){
    out[i] = 0;
    for(j = 0;j <= 55;j++){
      cnt[j][i] = 0;
    }
  }

  for(i = 0;i < n;i++){
    k = strlen(s[i]);
    for(j = 0;j < k;j++){
      cnt[i][s[i][j] - 'a']++;
    }
  }

  int mn;
  for(i = 0;i < 26;i++){
    mn = 100100100;
    for(j = 0;j < n;j++){
      if(mn > cnt[j][i]) mn = cnt[j][i];
    }

    out[i] = mn;
  }

  for(i = 0;i < 26;i++){
    if(out[i] != 0){
      for(j = 0;j < out[i];j++){
        printf("%c", 'a' + i);
      }
    }
  }

  printf("\n");

  return 0;
}
