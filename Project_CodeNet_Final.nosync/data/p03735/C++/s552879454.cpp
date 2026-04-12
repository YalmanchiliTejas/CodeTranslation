#include <bits/stdc++.h>

using namespace std;
const int N = 200001;
int n;
vector<pair<int, int>> v;
void mx(int& a, int b){
  if(a < b)
    a = b;
}
void mn(int& a, int b){
  if(a > b)
    a = b;
}
pair<int, int> solve_sub(vector<pair<int, int>> v){
  int m = v.size();
  if(m == 0)
    return {1000000000, 0};
  int x[m];
  int y[m];
  int a, b;
  for(int i = 0;i < m;i++)
    x[i] = v[i].first, y[i] = v[i].second;
  int b_min, b_max;
  int res = 1e9 + 1;
  b_max = x[m - 1];
  int mny, mni;
  mny = 1e9 + 1;
  for(int i = 0;i < m;i++){
    if(y[i] < mny){
      mny = y[i];
      mni = i;
    }
  }
  for(int i = 0;i < m;i++){
    if(x[i] > mny)break;
    b_min = x[i];
    if(b_max - b_min < res){
      res = b_max - b_min;
      a = b_min, b = b_max;
    }
    b_max = max(b_max, y[i]);
  }

  b_max = 0;
  for(int i = 0;i < m;i++){
    if(i == mni){
      mx(b_max, y[i]);
    }else{
      if(x[i] < mny)
        mx(b_max, y[i]);
      else
        mx(b_max, x[i]);
    }
  }
  if(b_max - mny < res){
    a = mny, b = b_max;
  }
  res = min(res, b_max - mny);
  return {a, b};
}

int main(){
  cin >> n;
  if(n == 1){
    cout << 0;
    return 0;
  }
  v.resize(n);
  for(auto& el : v){
    cin >> el.first >> el.second;
    if(el.first > el.second)
      swap(el.first, el.second);
  }

  sort(v.begin(), v.end());
  long long res = 1e18 + 1;
  int r_min = v[0].first;
  int r_max, b_min, b_max;
  int mxi, mxy, mni, mny;
  mxy = -1;
  mny = 1e9 + 1;
  for(int i = 0;i < n;i++){
    if(v[i].second > mxy){
      mxy = v[i].second;
      mxi = i;
    }
    if(v[i].second < mny){
      mny = v[i].second;
      mni = i;
    }
  }
  // case 1: b_max is max
  res = 1ll * (v[n - 1].first - v[0].first) * (mxy - mny);

  // cases 2: 
  r_max = mxy;
  vector<pair<int, int>> sub;
  for(int i = 0;i < n;i++){
    if(i == 0 || i == mxi)continue;
    sub.push_back(v[i]);
  }
  pair<int, int> sol = solve_sub(sub);
  mn(sol.first, v[0].second);
  mn(sol.first, v[mxi].first);
  mx(sol.second, v[0].second);
  mx(sol.second, v[mxi].first);
  res = min(res, 1ll * (r_max - r_min) * (sol.second - sol.first));
  cout << res;

}
