#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long patty_num(const int l,
                    const long long x,
                    const vector<long long>& patty,
                    const vector<long long>& bun,
                    const vector<long long>& all){
  if(l == 0){
    if(x <= 0){
      return 0;
    }else{
      return 1;
    }
  }

  if(x <= 1){
    return 0;
  }

  if(x >= all[l]){
    return patty[l];
  }

  long long ret =
    patty_num(l - 1, x - 1, patty, bun, all) +
    patty_num(l - 1, x - (1 + all[l - 1] + 1), patty, bun, all);
  if(x >= 1 + all[l - 1] + 1){
    ret += 1;
  }
  return ret;
}

int main(){
  int N;
  long long X;
  cin >> N >> X;

  vector<long long> all(N + 1), patty(N + 1), bun(N + 1);
  patty[0] = 1;
  all[0] = 1;
  for(int n = 1; n <= N; n++){
    patty[n] = 2 * patty[n - 1] + 1;
    bun[n] = 2 * bun[n - 1] + 2;
    all[n] = patty[n] + bun[n];
  }

  long long ans = patty_num(N, X, patty, bun, all);
  cout << ans << endl;

}
