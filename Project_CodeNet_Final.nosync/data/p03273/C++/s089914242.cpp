#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/integer/common_factor.hpp>
#include <boost/integer/common_factor_rt.hpp>

#define rep_ui(k,n)      for(ui  i = (k); i < (n); ++i)
#define rep_si(k,n)      for(int i = (k); i < (n); ++i)
#define rep_ul(k,n)      for(ul  i = (k); i < (n); ++i)
#define rep_sl(k,n)      for(ll  i = (k); i < (n); ++i)
#define rep_ui_down(k,n) for(ui  i = (k); i > (n); --i)
#define rep_si_down(k,n) for(int i = (k); i > (n); --i)
#define rep_ul_down(k,n) for(ul  i = (k); i > (n); --i)
#define rep_sl_down(k,n) for(ll  i = (k); i > (n); --i)

#define rep_uj(k,n)      for(ui  j = (k); j < (n); ++j)
#define rep_sj(k,n)      for(int j = (k); j < (n); ++j)
#define rep_uj_down(k,n) for(ui  j = (k); j > (n); --j)
#define rep_sj_down(k,n) for(int j = (k); j > (n); --j)

#define rep(k,n)         rep_ui(k,n)

typedef uintmax_t    ull;
typedef intmax_t     ll;
typedef uint64_t     ul;
typedef uint32_t     ui;
typedef uint8_t      uc;

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vc)
{
  for (auto it = vc.begin(); it != vc.end(); ++it)
  {
    if (std::next(it) == vc.end())
      os << *it;
    else
      os << *it << ' ';
  }
  return os;
}

template<class T1, class T2>
inline
std::ostream & operator<<(std::ostream & os, const std::pair<T1, T2> & p)
{
  return os << p.first << ' ' << p.second;
}

void solve(void)
{
  using std::string;
  using std::vector;
  using std::map;
  using std::pair;
  using std::cin;
  using std::cout;
  ui H{}, W{}; cin >> H >> W;
  vector<vector<char>> vc(H, vector<char>(W));
  rep(0, H)
  {
    string s{}; cin >> s;
    rep_uj(0, W)
      vc[i][j] = s[j];
  }

  rep(0, H)
  {
    ui cnt{};
    rep_uj(0, W)
      if(vc[i][j] == '.') ++cnt;
    if(cnt == W)
    {
      rep_uj(0, W)
        vc[i][j] = ' ';
    }
  }
  rep_uj(0, W)
  {
    ui cnt{};
    rep(0, H)
      if(vc[i][j] == '.' || vc[i][j] == ' ') ++cnt;
    if(cnt == H)
    {
      rep(0, H)
        vc[i][j] = ' ';
    }
  }

  rep(0, H)
  {
    ui flg{};
    rep_uj(0, W)
    {
      if(vc[i][j] != ' ')
      {
        cout << vc[i][j];
        flg = true;
      }
    }
    if(flg) cout << '\n';
  }
  // cout << ans << '\n';
  return;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  solve();

  return 0;
}
