#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define bitrep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
using ll = long long;
using pii = pair<int, int>;
using si = set<int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 100'000'000;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

template <typename T>
vector<T> getSumVec(vector<T> vec){
    vector<T> values(vec.size()+1,0);
    for(ll i=0;i<values.size()-1;i++){
      values.at(i+1) = values.at(i) + vec.at(i);
    }
    return values;
}

string S;
ll N,cnt;

int main(){
  cin >>N;
  ll ans = 0;
  auto inputs = getValues<ll>(N);
  auto sums = getSumVec<ll>(inputs);
  rep(i,N){
    ll sumMod = (sums.at(N) - sums.at(i+1)) % modSeed;
    ans += sumMod * inputs.at(i);
    ans %= modSeed;
  }
  printl(ans);
}
