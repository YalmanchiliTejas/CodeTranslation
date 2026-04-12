#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;


int main(){
  int n;
  cin >> n;
  int cont[n]['z'-'a'+1]={0};
  rep(i,n){
    string s;
    cin >> s;
    sort(all(s));
    for(int j=0;j<s.size();j++){
      cont[i][s.at(j)-97]++;
    }
  }

  for(int i=0;i<'z'-'a'+1;i++){
    int m = INF;
    for(int j=0;j<n;j++){
      int x = cont[j][i];
      m = min(x,m);
    }

    for(int k=0;k<m;k++){
      printf("%c",'a'+i);
    }

  }
}