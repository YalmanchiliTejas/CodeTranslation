#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
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
ll A,B,C,X,Y,ans;

int main(){
  ans = 0;
  cin >> A>>B>>C>>X>>Y;
  for(ll c=0;c<=max(2*X,2*Y);c++){
    if(c%2!=0) continue;
    ll a = max(0LL,X - c/2);
    ll b = max(0LL,Y -c/2);
    if(ans==0){
      ans = a*A+b*B+c*C;
    }else{
      ans = min(a*A+b*B+c*C,ans);
    }
  }
  printl(ans);
}
