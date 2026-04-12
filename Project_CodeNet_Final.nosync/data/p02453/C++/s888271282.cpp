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
  int n; cin >> n;
  vector<int> nums(n);
  rep_i(i, n){
    cin >> nums[i];
  }

  int q; cin >> q;
  int tmp;
  rep_i(i, q){
    cin >> tmp;
    vector<int>::iterator itr = lower_bound(nums.begin(), nums.end(), tmp);
    cout << itr - nums.begin() << endl;
    // if(binary_search(nums.begin(), nums.end(), tmp)){
    //   say(1);
    // }else{
    //   say(0);
    // }
  }
}
