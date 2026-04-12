#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1000003;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

int main() {
  string S;
  int K;
  cin >> S >> K;

  if(K == 3) {

    int64 ret = 0;
    {
      string T;
      for(int i = 0; i < S.size(); i++) T += "0";

      int i = 0;
      for(int j = i + 1; j < S.size(); j++) {
        for(int k = j + 1; k < S.size(); k++) {
          for(int l = '1'; l <= '9'; l++) {
            for(int m = '1'; m <= '9'; m++) {
              for(int n = '1'; n <= '9'; n++) {
                T[i] = l;
                T[j] = m;
                T[k] = n;
                ret += T <= S;
                T[i] = '0';
                T[j] = '0';
                T[k] = '0';
              }
            }
          }
        }
      }
    }

    {
      for(int i = 1; i < S.size(); i++) {
        for(int j = i + 1; j < S.size(); j++) {
          for(int k = j + 1; k < S.size(); k++) {
            ret += 9 * 9 * 9;
          }
        }
      }
    }
    cout << ret << endl;
  } else if(K == 2) {

    int64 ret = 0;
    {
      string T;
      for(int i = 0; i < S.size(); i++) T += "0";

      int i = 0;
      for(int j = i + 1; j < S.size(); j++) {
        for(int l = '1'; l <= '9'; l++) {
          for(int m = '1'; m <= '9'; m++) {
            T[i] = l;
            T[j] = m;
            ret += T <= S;
            T[i] = '0';
            T[j] = '0';
          }
        }
      }
    }

    {
      for(int i = 1; i < S.size(); i++) {
        for(int j = i + 1; j < S.size(); j++) {
          ret += 9 * 9;
        }
      }
    }
    cout << ret << endl;
  } else {

    int64 ret = 0;
    {
      string T;
      for(int i = 0; i < S.size(); i++) T += "0";
      int i = 0;
      for(int l = '1'; l <= '9'; l++) {
        T[i] = l;
        ret += T <= S;
        T[i] = '0';
      }
    }

    {
      for(int i = 1; i < S.size(); i++) {
        ret += 9;
      }
    }
    cout << ret << endl;

  }

}
