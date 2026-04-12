#include <bits/stdc++.h>
using namespace std;
  
// #define int long long
#define pb push_back
  
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
 
template <class X> void print(X Target){ cout << Target << '\n'; }

struct PRO{
  int num;
  int pt;
};

bool comp(PRO lhs, PRO rhs){
  return (lhs.pt > rhs.pt);
}

signed main()
{
  ios::sync_with_stdio(false);
  vector<PRO> pro;
  char c; // , mushi
  int n, p;

  while (cin >> n >> c >> p, n || p){
    pro.pb((PRO){n, p});
  }
  sort(pro.begin(), pro.end(), comp);
  map<int, int> mp;
  for (int i = 0, j = 1; i < pro.size(); i++){
    if (i != pro.size() - 1 && pro[i].pt != pro[i + 1].pt){
      mp[pro[i].num] = j++;
    }
    else {
      mp[pro[i].num] = j;
    }
  }
  int input;
  while (cin >> input){
    print(mp[input]);
  }

  return (0);
}