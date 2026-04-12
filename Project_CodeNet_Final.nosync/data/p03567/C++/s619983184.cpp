#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  int n;
  char s[6];
  scanf("%s",s);
  n=strlen(s);
  for(int i=0;i<n-1;i++)
    if(s[i]=='A'&&s[i+1]=='C'){
      printf("Yes\n");
      return 0;
    }
  printf("No\n");
}