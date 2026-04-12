#include <bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep_i(i, n) for (int i = 0; i < (n); ++i)
#define rep_ll(i, n) for (long long i = 0; i < (n); ++i)
#define r_rep_i(i, start, end) for (int i = (start); i < (end); ++i)
#define r_rep_ll(i, start, end) for (long long i = (start); i < (end); ++i)
#define debug_vi(v) copy((v).begin(), (v).end(), ostream_iterator<int>(cout, " "));
#define debug_vll(v) copy((v).begin(), (v).end(), ostream_iterator<long long>(cout, " "));
#define debug_vd(v) copy((v).begin(), (v).end(), ostream_iterator<double>(cout, " "));
#define sort_v(v) sort((v).begin(), (v).end()); //昇順
#define d_sort_vi(v) sort((v).begin(), (v).end(), greater<int>()); //降
#define d_sort_vll(v) sort((v).begin(), (v).end(), greater<long long>()); //降
#define d_sort_vd(v) sort((v).begin(), (v).end(), greater<double>()); //昇順
#define say(t) cout << (t) << endl;
#define sum_vi(v) accumulate((v).begin(), (v).end(), 0);
#define sum_vll(v)accumulate((v).begin(), (v).end(), 0LL);

ll gcd(ll a, ll b) { return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a, b)*b;}
const int IINF=(1<<30);
const ll LLINF = 1LL<<60;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;cin >> n;
  vector<string> hoge(n);
  vector<int> Alpha(26, 100000);
  string tmp;
  rep_i(i, n){
    cin >> tmp;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < Alpha.size(); i++){
      char a = 97 + i;
      int count = 0;
      for (int t = 0; t < tmp.length(); t++){
        if(tmp[t] == a){
          count += 1;
        }
      }
      if(count <= Alpha[i]){
        Alpha[i] = count;
      }
    }
  }
  string ans;
  char al;
  rep_i(i, 26){
    for (int v = 0; v < Alpha[i]; v++){
      al = 97 + i;
      ans += al;
    }
  }
  say(ans);
  // vector<char> common(hoge[0].length());
  // rep_i(i, hoge[0].length()){
  //   common[i] = hoge[0][i];
  // }
  // vector<int> ng;
  // for(int i = 1; i < n; i++){
  //   for(int v = 0; v < common.size(); v++){
  //     if(hoge[i].find(common[v]) == string::npos){
  //       common[v] = 0;
  //     }
  //   }
  // }

  // string ans;
  // rep_i(i, common.size()){
  //   if(common[i] == 0){
  //     continue;
  //   }
  //   ans += common[i];
  // }
  
  // say(ans);
}