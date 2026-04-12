#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REV(c) reverse((c).begin(),(c).end())

using namespace std;
typedef pair<int,int> P;

// 最大公約数
int64_t gcd(int64_t a, int64_t b) {
  return b != 0 ? gcd(b, a % b) : a;
}

// 最小公倍数
int64_t lcm(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
}

int ctoi(char c){
  return c - '0';
}

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> vec(n);
  REP(i,n){
    cin >> vec.at(i);
  }
  vector<int64_t> vec2;
  REP(i,n){
    if (vec2.size() == 0){
      vec2.push_back(vec.at(i));
    }else{
      auto tmp = lower_bound(ALL(vec2), vec.at(i)) - vec2.begin();
      if (tmp == 0){
        vec2.insert(vec2.begin(), vec.at(i));
      }else{
        vec2.at(tmp-1) = vec.at(i);
      }
      
    }
  }
  cout << vec2.size() << endl;
  return 0;
}

