#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;


bool check(int n, vector<int> t, vector<char> s){
  int l,r;
  l = (n == 0 ? t.size()-1 : n-1);
  r = (n == t.size() - 1 ? 0 : n+1);

  bool flag=true;
  if(t[n] == 0){
    if(s[n]=='o'){
      if(t[l] != t[r])flag=false;
    }else{
      if(t[l] == t[r])flag=false;
    }
  }else{
    if(s[n]=='x'){
      if(t[l] != t[r])flag=false;
    }else{
      if(t[l] == t[r])flag=false;
    }
  }

  return flag;
}

void printAns(vector<int> v){
  REP(i,v.size()){
    cout << (v[i] == 0 ? "S" : "W");
  }
  cout << endl;
  exit(0);
}

int main(){
  int N;
  cin >> N;
  
  vector<char> s(N);
  REP(i,N){
    char c;
    cin >> c;
    s[i] = c;
  }

  // 羊：0、狼：1
  REP(i,4){
    vector<int> t(N);
    t[0] = i&1;
    t[1] = (i>>1)&1;

    FOR(i,1,N-1){
      if(t[i] == 0){
        if(s[i]=='o') t[i+1] = t[i-1];
        else t[i+1] = t[i-1]^1;
      }else{
        if(s[i]=='o') t[i+1] = t[i-1]^1;
        else t[i+1] = t[i-1];
      }
    }

    if(check(0,t,s) && check(N-1,t,s))printAns(t);

  }
  cout << -1 << endl;
}