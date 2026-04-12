#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)     for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = m; i < (int)(n); i++)

#define MOD 1000000007
int arrayMax(vector<int> p,int idx){
  int max_Val = p.at(0);
  rep(i,idx){
    max_Val = max(max_Val,p.at(i)); 
  }
  
  return max_Val;
}

int main() {
  int N;
  cin >> N;
  
  vector<int> Hi;
  rep(i,N){
    int tmpHi;
    cin >> tmpHi;
    Hi.push_back(tmpHi);
  }

  int ans = 1;
  rep(i,N){
    if(i == 0) continue;
    int Himax = arrayMax(Hi,i);
    if(Hi.at(i) >= Himax) ans++;
  }
  
  cout << ans << endl;
  return 0;
}