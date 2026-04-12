#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  vint ans(26,INF);
  string ANS;
  int n;
  cin >> n;
  rep(i,n){
    string a;
    cin >> a;
    vint temp(26,0);
    rep(j,a.size()){
      temp[a[j]-97]++;
    }
    rep(j,26){
      ans[j] = min(ans[j],temp[j]);
    }
  }
  rep(i,26){
    while(ans[i] > 0){
      ANS.push_back(i+97);
      ans[i]--;
    }
  }
  cout << ANS << endl;
}