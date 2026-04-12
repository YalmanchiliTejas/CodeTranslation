#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool morePair(const ipair& l, const ipair& r){return l.second > r.second;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = 1e9 + 7;
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }

int main() {
   int N;
   cin >> N;
   int H[N];
   int cnt = 1;
   int max = 0;
   for (int i = 0; i < N; i++) {
      cin >> H[i];
      if (i == 0) max = H[i];
      if (i != 0 && H[i] >= max) {
         cnt++;
         max = H[i];
      }
   }
   cout << cnt << endl;
   return 0;
}
