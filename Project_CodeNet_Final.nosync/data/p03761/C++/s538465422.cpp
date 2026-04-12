#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i,N) for(int i=0;i<((int)N);i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
int main(void){
  int N; cin>>N;
  char abc[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
  char str[N][51];
  for(int i=0;i<N;i++){
      cin>>str[i];
  }
  int check[N][26];
  for(int i=0;i<N;i++){
      for(int j=0;j<26;j++){
          check[i][j]=0;
      }
  }
  for(int i=0;i<N;i++){
      int len=strlen(str[i]);
      for(int j=0;j<len;j++){
          int alpha=str[i][j]-'a';
          check[i][alpha]++;
      }
  }
  int ans[26];
  for(int i=0;i<26;i++){ int min=100;
     for(int j=0;j<N;j++){
        if(check[j][i]<min) min=check[j][i];
         
     }
     ans[i]=min;
  }
  for(int i=0;i<26;i++){
    for(int j=0;j<=ans[i];j++){
        if(j!=0){cout<<abc[i];}
    }
  }
  return 0;
}
