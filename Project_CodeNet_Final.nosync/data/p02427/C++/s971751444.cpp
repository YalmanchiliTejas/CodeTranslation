#include <bits/stdc++.h>
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
#define d_sort_vd(v) sort((v).begin(), (v).end(), greater<double>()); //昇順
#define say(t) cout << (t) << endl;
#define sum_vi(v) accumulate((v).begin(), (v).end(), 0);
#define sum_vll(v)accumulate((v).begin(), (v).end(), 0LL);

int main(){
  int n;cin >> n;
  vector<int> posi;
  for (int i = 0; i < (1 << n); i++){
    // cout << i << endl;
    // cout << bitset<8>(i) << endl;
    for (int v = 0; v < n; v++){
      if(i & (1 << v)){
        posi.push_back(v);
      }
    }
    cout << i << ":";
    if (!posi.empty()){
      for (auto itr = posi.begin(); itr != posi.end(); itr++){
        cout << " " << *itr;
      }
    }
    cout << endl;
    posi.clear();
  }
}
