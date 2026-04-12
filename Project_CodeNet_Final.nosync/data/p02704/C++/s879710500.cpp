#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int ok = 1;
int n;
ostream& operator<<(ostream& out, const vector<vector<int>>& arr){
  for(auto& el : arr){
    for(auto& e : el){
      out << e << ' ';
    }
    out << endl;
  }
  return out;
}

vector<vector<int>> solve_layer(vector<int> s, vector<int> t, vector<ll> u, vector<ll> v){
  vector<vector<int>> mat;
  mat.resize(n, vector<int>(n, -1));
  set<int> remr;
  set<int> remc;
  for(int i = 0;i < n;i++){
    if(s[i] == u[i])
      remr.insert(i);
  }
  for(int i = 0;i < n;i++){
    if(t[i] == v[i])
      remc.insert(i);
  }
  for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
      if(u[i] == v[j]){
        mat[i][j] = u[i];
      }else if(s[i] == 0 && u[i] == 1){
        mat[i][j] = 1;
      }else if(s[i] == 1 && u[i] == 0){
        mat[i][j] = 0;
      }else if(t[j] == 0 && v[j] == 1){
        mat[i][j] = 1;
      }else if(t[j] == 1 && v[j] == 0){
        mat[i][j] = 0;
      }
//  cout << (mat) << endl;
  for(int i = 0;i < n;i++){
    if(s[i] == 0 && u[i] == 0){
      for(int j = 0;j < n;j++){
        if(mat[i][j] == 0){
          remr.erase(i);
          break;
        }
      }
    }else if(s[i] == 1 && u[i] == 1){
      for(int j = 0;j < n;j++){
        if(mat[i][j] == 1){
          remr.erase(i);
          break;
        }
      }
    }
  }

  for(int i = 0;i < n;i++){
    if(t[i] == 0 && v[i] == 0){
      for(int j = 0;j < n;j++){
        if(mat[j][i] == 0){
          remc.erase(i);
          break;
        }
      }
    }else if(t[i] == 1 && v[i] == 1){
      for(int j = 0;j < n;j++){
        if(mat[j][i] == 1){
          remc.erase(i);
          break;
        }
      }
    }
  }
  if(remr.size() > 1 && remc.size() > 1){
    int s = 0;
    int p = 0;
    for(auto r : remr){
      p = s;
      for(auto c : remc){
        mat[r][c] = p;
        p ^= 1;
      }
      s ^= 1;
    }
  }

  for(auto el : remr){
    for(int j = 0;j < n;j++){
      if(mat[el][j] != -1)continue;
      mat[el][j] = u[el];
    }
  }
  for(auto el : remc){
    for(int j = 0;j < n;j++){
      if(mat[j][el] != -1)continue;
      mat[j][el] = v[el];
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(mat[i][j] == -1)
        mat[i][j] = 0;
//      cout << mat[i][j] << ' ';
    }
//    cout << endl;
  }
//  cout << (mat) << endl;;
  vector<int> orr, orc, andr, andc;
  orr.resize(n, 0);
  orc.resize(n, 0);
  andr.resize(n, 1);
  andc.resize(n, 1);

  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      int el = mat[i][j];
      orr[i] = orr[i] | el;
      orc[j] = orc[j] | el;
      andr[i] = andr[i] & el;
      andc[j] = andc[j] & el;
    }
  }
  for(int i = 0;i < n;i++){
    if(s[i] == 0 && andr[i] != u[i]){
      ok = 0;
    }
    if(s[i] == 1 && orr[i] != u[i])
      ok = 0;
  }
  for(int i = 0;i < n;i++){
    if(t[i] == 0 && andc[i] != v[i]){
      ok = 0;
    }
    if(t[i] == 1 && orc[i] != v[i])
      ok = 0;
  }
  return mat;
}
void shift(vector<vector<ll>>& arr){
  for(auto& el : arr)
    for(auto& e : el)
      e <<= 1;
}
void vor(vector<vector<ll>>& a, const vector<vector<int>>& b){
    assert(a.size() == b.size());
    for(int i = 0;i < a.size();i++){
      assert(a[i].size() == b[i].size());
      for(int j = 0;j < a[i].size();j++){
        a[i][j] |= b[i][j];
      }
    }
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  vector<int> s;
  vector<int> t;
  vector<ll> u;
  vector<ll> v;
  s.resize(n);
  t.resize(n);
  u.resize(n);
  v.resize(n);
  for(auto& el : s)
    cin >> el;
  for(auto& el : t)
    cin >> el;
  for(auto& el : u)
    cin >> el;
  for(auto& el : v)
    cin >> el;
  vector<vector<ll>> res(n, vector<ll>(n));
  for(int i = 63;i >= 0;i--){
    vector<ll> lu = u, lv = v;
    for(int j = 0;j < n;j++){
      lu[j] = (lu[j] & (1ull << i)) >> i;
      lv[j] = (lv[j] & (1ull << i)) >> i;
    }
    vector<vector<int>> mat = solve_layer(s, t, lu, lv);
    shift(res);
    vor(res, mat);
  }
  if(ok == 0){
    cout << -1;
  }else{
    for(int i = 0;i < n;i++){
      for(int j = 0;j < n;j++){
        cout << res[i][j] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
