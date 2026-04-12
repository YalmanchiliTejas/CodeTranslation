#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int num[3];
  rep(i,3){
    cin >> num[i];
  }

  rep(i,1){
    int x = 100*num[i]+10*num[(i+1)%3]+num[(i+2)%3];
    if(x%4==0){
      puts("YES");
      return 0;
    }
  }

  puts("NO");
  return 0;
}