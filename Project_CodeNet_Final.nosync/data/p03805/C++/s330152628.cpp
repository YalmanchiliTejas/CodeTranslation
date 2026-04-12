#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 1'000'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll N,M,ans;

int main(){
  ans = 0;
  cin >> N>>M;
  vector<int> pattern(N);
  rep(i,N){
    pattern[i] = i+1;
  }

  vector<set<int>> direc(N+1);
  for(int i=1;i<=M;i++){
    int a,b;
    cin >>a>>b;
    if(!direc[a].count(b)){
      direc[a].insert(b);
    }
    if(!direc[b].count(a)){
      direc[b].insert(a);
    }
  }

  do{
    if(pattern[0]!=1) continue;
    bool flg = true;
    for(int i=0;i<N-1;i++){
      if(!direc[pattern[i]].count(pattern[i+1])) {
        flg = false;
        break;
      }
    }
    if(flg) ans++;
  }while(next_permutation(pattern.begin(),pattern.end()));

  printl(ans);
}
