#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(long i=0; i<(long)(n);i++)
#define REP(i,s,t) for(long i=s; i<t; i++)
#define RNG(i,s,t,u) for(long i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
  long n,x,m;
  cin >> n >> x >> m;
  vl div(100001);
  for(long i=0; i<100001; i++){
    div.at(i) = i * i % m;
  }
  set<long> st;
  vl list;
  long tmp = x;
  rep(i,n){
    if(i==0){
      st.insert(x);
      list.push_back(x);
      continue;
    }else{
      tmp = div.at(tmp);
      if(st.count(tmp)){
        break;
      }else{
        st.insert(tmp);
        list.push_back(tmp);
      }
    }
  }
  if(n == list.size()){
    long sum = 0;
    rep(i,n) sum += list.at(i);
    cout << sum << endl;
    return 0;
  }else{
    long len;
    long sum = 0;
    rep(i,list.size()){
      if(list.at(i) != tmp){
        sum += list.at(i);
      }else{
        len = list.size() - i;
        long sub = 0;
        REP(j,i,list.size()){
          sub += list.at(j);
        }
        long r = n - i;
        sum += (r/len)*sub;
        r %= len;
        REP(j,i,i+r){
          sum += list.at(j);
        }
        cout << sum << endl;
        break;
      }
    }
  }
}