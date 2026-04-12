#include<cstdio>
#include<algorithm>
using namespace std;

int main(void){
  int s[100][100]={};
  int n;
  char c;

  scanf("%d",&n);

  for(int i=0;i<=n;i++){
    while((c=getchar())!='\n'){
      s[i][c-'a']++;
    }
  }
  for(int i=2;i<=n;i++){
    for(int j=0;j<26;j++){
      s[i][j]=min(s[i][j],s[i-1][j]);
    }
  }

  for(int i=0;i<26;i++){
    while(s[n][i]>0){
      putchar(i+'a');
      s[n][i]--;
    }
  }

  putchar('\n');

  return 0;
}
