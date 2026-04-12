#include <bits/stdc++.h>
using namespace std;

#define SORT(c) sort((c).begin(), (c).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
#define ANS(ans) cout << (ans) << endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;
typedef pair<int, int> P;

//repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define REP(i, n) for (long long i = 0; i < (n); ++i)

struct Mystruct{
    long long atack;
    long long mp;
    double cost;

    Mystruct(long long input_a, long long input_b){
        atack = input_a;
        mp = input_b;
        cost = input_a*1.0 / input_b;
    }
    bool operator<(const Mystruct &another) const
    {
        if(cost == another.cost){
            return mp < another.mp;
        }
        return cost < another.cost;//年齢を比較
    };
};

int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  long long ans = 1000000000;
  for (int i = 0; i <= max(x, y) * 2; i += 2) {
    long long tmp = max(0,(x - i / 2)) * a + max(0,(y - i / 2)) * b + i * c;
    ans = min(ans, tmp);
  }
  ANS(ans);
  return 0;
}
