#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)

int main(){
  int n;
  cin >> n;
  int a[26];
  rep(i,26){
    a[i] = INF;
  }
  int tmp[26]={};
  rep(i,n){
    string s;
    cin >> s;
    rep(j,26){
      tmp[j] = 0;
    }
    rep(j,s.size()){
      tmp[s[j]-'a'+0]++;
    }
    rep(j,26){
      a[j] = min(a[j],tmp[j]);
    }
  }
  
  string alp = "abcdefghijklmnopqrstuvwxyz";
  
  rep(i,26){
    rep(j,a[i]){
      cout << alp[i];
    }
  }
  cout << endl;
}