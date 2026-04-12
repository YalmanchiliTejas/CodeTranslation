#include <bits/stdc++.h>
#define mp(a,b)   make_pair(a,b)
#define ll        long long
#define mp(a,b)   make_pair(a,b)
#define si(n)     scanf("%d",&n)
#define sl(n)     scanf("%lld",&n)
#define pi(n)     printf("%d\n",n)
#define pl(n)     printf("%lld\n",n)
#define           newline cout << endl;
#define           ff first
#define           ss second
using namespace std;

int main(){
  //clock_t tStart = clock();
  int n,m;
  cin >> n >> m;
  char arr[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> arr[i][j];
    }
  }
  bool check[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) check[i][j]=1;
  }
  for(int i=0;i<n;i++){
    bool f = 0;
    for(int j=0;j<m;j++){
      if(arr[i][j]=='#') f=1;
    }
    if(!f){
      for(int j=0;j<m;j++){
        check[i][j]=0;
      }
    }
  }
  for(int j=0;j<m;j++){
    bool f = 0;
    for(int i=0;i<n;i++){
      if(arr[i][j]=='#') f=1;
    }
    if(!f){
      for(int i=0;i<n;i++){
        check[i][j]=0;
      }
    }
  }
  for(int i=0;i<n;i++){
    int cnt =  0;
    for(int j=0;j<m;j++){
      if(check[i][j]) cnt++;
    }
    if(cnt>=1){
      for(int j=0;j<m;j++){
        if(check[i][j]) cout << arr[i][j];
      }
      newline
    }
  } newline
  //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}