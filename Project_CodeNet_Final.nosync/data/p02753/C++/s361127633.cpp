#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

std::string S;
int cnt[2];

int main()
{
  std::cin >> S;

  rep( i, 3 )
    ++cnt[S[i]-'A'];

  std::cout << (cnt[0]&&cnt[1] ? "Yes" : "No" ) << std::endl;

  return 0;
}