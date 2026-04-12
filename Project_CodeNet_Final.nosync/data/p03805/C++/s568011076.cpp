#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> make_permutation(int N)
{
    vector<vector<int>> pos;
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    do {
        if (v.at(0) == 1)
        {
          pos.push_back(v);
        }
    } while( next_permutation(v.begin(), v.end()) );
    return pos;

    // for (int i = 0; i < 6; i++)
    // {
    //   cout << pos.at(i).at(0);
    //   cout << pos.at(i).at(1);
    //   cout << pos.at(i).at(2) << endl;
    // }
}

int main()
{
  int N,M;
  int ans = 0;
  cin >> N >> M;
  vector<bitset<8>> conect(N);
  int a,b;
  vector<vector<int>> pos = make_permutation(N);
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    conect.at(a - 1).set(b - 1);
    conect.at(b - 1).set(a - 1);
  }

  for (vector<int> tops : pos)
  {
    for (int i = 0; i < N - 1; i++)
    {
      if (conect.at(tops.at(i) - 1).test(tops.at(i + 1) - 1))
      {
        if (i == N - 2)
        {
          ans++;
          // for (int t : tops)
          // {
          //   cout << t;
          // }
          // cout << endl;
        }
        continue;
      }
      else
      {
        break;
      }
    }
  }
  cout << ans << endl;
}