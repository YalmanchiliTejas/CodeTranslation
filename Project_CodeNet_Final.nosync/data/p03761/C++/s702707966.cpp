#include<bits/stdc++.h>    

# define F first
# define S second
# define mp make_pair
# define pii pair<int,int>

# define long long long
# define pb push_back
# define sz(a) (int)(a.size())

# define y1     tipa_y1
# define left   tipa_left
# define right  tipa_right

const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const long MXLL = 4611686018427387903;
const int Sz = 1110111;

using namespace std;

inline void Read_rap () {
  ios_base :: sync_with_stdio(0);
  cin.tie(0);
}
int n;
             
string s;

int p[Sz];

int cnt[Sz];

int main()
{
  Read_rap ();
  cin >> n;
  for (int i = 1;i <= n;i ++) {
    cin >> s;
    for (char c : s)
      cnt[c - 'a'] ++;
                            
    if (i == 1)
      for (int i = 0;i < 26;i ++)
        p[i] = cnt[i], cnt[i] = 0;
    else
      for (int i = 0;i < 26;i ++)
        p[i] = min (p[i], cnt[i]), cnt[i] = 0; 
  }
  for (int i = 0;i < 26;i ++)
    while (p[i] --)
      cout << char (i + 'a');

  return 0;
}









// Coded by Z...
