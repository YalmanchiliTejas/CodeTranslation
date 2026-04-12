#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
  int N ,M;
  cin >> N >> M;
  
  vector<vector<int>> ab(M, vector<int>(2));
  rep (i, M)
  {
    cin >> ab.at(i).at(0) >> ab.at(i).at(1); 
  }
  
  vector<int> v;
  rep (i, N)
  {
    v.push_back(i+1);
  }
  
  bool total_flag;
  bool flag;
  int count = 0;
  do {
    if (v.at(0) != 1)
      break;
    total_flag = true;
    for (int i = 0; i < N - 1; i++)
    {
      flag = false;
      rep(j ,M)
      {
        if( ab.at(j).at(0) == v.at(i) && ab.at(j).at(1) == v.at(i+1) )
        {
          //cout << v.at(i) << ' ' << v.at(i+1) << endl;
          flag = true;
          continue;
        }
        else if(ab.at(j).at(1) == v.at(i) && ab.at(j).at(0) == v.at(i+1))
        {
          //cout << v.at(i) << ' ' << v.at(i+1) << endl;
          flag = true;
          continue;
        }
      }
      if (flag == false)
      {
        total_flag = false;
      }
    }
    if (total_flag == true)
    {
      count++;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << count << endl;
  
}