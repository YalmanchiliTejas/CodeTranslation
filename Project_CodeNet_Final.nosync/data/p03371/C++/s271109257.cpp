#include <bits/stdc++.h>
#include <boost/functional/hash/hash.hpp>

typedef long long lnt;

#define LOOP(n) for (lnt _ = 0; _ < (n); _++)
#define REP(i, n) for (lnt i = 0; i < (n); i++)            // 0, 1, ..., n-1
#define INVREP(i, n) for (lnt i = (n)-1; i >= 0; i--)      // n-1, n-2, ..., 0
#define FOR(i, a, b) for (lnt i = (a); i < (b); i++)       // a, a+1, ..., b-1
#define INVFOR(i, a, b) for (lnt i = (b)-1; i >= (a); i--) // b-1, b-2, ..., a
#define ALL(a) a.begin(), a.end()
#define DISPLAY_DOUBLE(d) (cout << scientific << setprecision(15) << (d))
#define INF (lnt)(1e18)

lnt MOD = (1e9 + 7); // AtCoderのMOD

//グローバル変数のMODを変更する
inline void CHANGE_MOD(const lnt &n) {
  MOD = n;
}

// 習慣付けの為'int'を一切タイプしない
#define MAIN int main

// 各アルゴリズムをlntに揃える
template <class InputIterator, class T>
lnt inline CNT(const InputIterator &first, const InputIterator &last,
               const T &value) {
  return std::count(first, last, value);
}

template <class InputIterator>
lnt inline DIST(const InputIterator &first, const InputIterator &last) {
  return std::distance(first, last);
}

template <class T> lnt inline SIZE(const T &sequence) {
  return (lnt)(sequence.size());
}

lnt inline ABS(const lnt &value) { return std::abs(value); }

lnt inline MAX(const lnt &value1, const lnt &value2) {
  return std::max(value1, value2);
}

lnt inline MIN(const lnt &value1, const lnt &value2) {
  return std::min(value1, value2);
}

template <class InputIterator>
lnt inline ACC(const InputIterator &first, const InputIterator &last,
               const lnt &init = 0) {
  return std::accumulate(first, last, init);
}

template <class InputIterator>
lnt inline SUM(const InputIterator &first, const InputIterator &last) {
  return std::accumulate(first, last, (lnt)0);
}

template <class InputIterator, class BinaryOperation>
lnt inline ACC(const InputIterator &first, const InputIterator last,
               const lnt init, const BinaryOperation binary_op) {
  return std::accumulate(first, last, init, binary_op);
}

// unordered_set，unordered_mapの為のハッシュの拡張
template <class T> struct boost_hash {
  inline std::size_t operator()(const T &val) const {
    return boost::hash_value(val);
  }
};

template <class T> using SET = std::unordered_set<T, boost_hash<T>>;
template <class T, class S> using MAP = std::unordered_map<T, S, boost_hash<T>>;

// pythonのsetdefaultメソッド
template <class T, class S>
S &setdefault(MAP<T, S> &map, const T &key, const S &val) {
  if (map.count(key)) {
    return map.at(key);
  }
  map.emplace(key, val);
  return map.at(key);
}

// next_partial_permutation関数
template <class BidirectionalIterator>
bool next_partial_permutation(BidirectionalIterator first,
                              BidirectionalIterator middle,
                              BidirectionalIterator last) {
  reverse(middle, last);
  return next_permutation(first, last);
}

template <class BidirectionalIterator, class Compare>
bool next_partial_permutation(BidirectionalIterator first,
                              BidirectionalIterator middle,
                              BidirectionalIterator last, const Compare comp) {
  reverse(middle, last, comp);
  return next_permutation(first, last, comp);
}

// vector<lnt>({first, first+1, ..., first + size - 1})を生成
std::vector<lnt> init_comb(const lnt size, const lnt first = 0) {
  std::vector<lnt> v;
  REP(i, size) { v.push_back(i + first); }
  return v;
}

// next_combination関数
// vector<lnt>の昇順列vと, 数Nを入力すると， {順列:N未満の数からなる相異なる#v要素の昇順列}
// の中で， 辞書順でvを次の順列に変更し， trueを返す． もし最後の順列だったら， 何もせずfalseを返す.
// 例：v = {0, 1}, N = 4 なら， {0, 1} → {0, 2} → {0, 3} → {1, 2} → {1, 3} → {2, 3}
bool next_combination(std::vector<lnt> &v, const lnt last) {
  if (SIZE(v) == 1 and v.at(0) != last - 1) {
    v.at(0)++;
    return true;
  }
  if (SIZE(v) == 1) {
    return false;
  }
  if (SIZE(v) > 1) {
    std::vector<lnt> w = v;
    w.erase(w.begin());
    if (next_combination(w, last)) {
      v = std::vector<lnt>(1, v.at(0));
      v.insert(v.end(), ALL(w));
      return true;
    }
    if (v.at(0) == last - SIZE(v)) {
      return false;
    }
    v = init_comb(SIZE(v), v.at(0) + 1);
    return true;
  } else
    return false;
}

// n以下の素数列挙
std::vector<lnt> Primes(const lnt n) {
  if (n < 2) {
    return std::vector<lnt>(0);
  }

  std::vector<lnt> vcPri, vcTab(n - 1);
  for (lnt i = 2; i < n + 1; i++) {
    vcTab[i - 2] = i;
  }

  const lnt nRoot = sqrt(n);
  while (vcTab[0] <= nRoot) {
    vcPri.push_back(vcTab[0]);
    vcTab.erase(vcTab.begin());
    std::vector<lnt> vcTab_fil;
    vcTab_fil.reserve(SIZE(vcTab));
    std::copy_if(vcTab.begin(), vcTab.end(), back_inserter(vcTab_fil),
                 [&vcPri](lnt x) -> bool { return x % vcPri.back(); });
    vcTab = vcTab_fil;
    if (vcTab.empty()) {
      break;
    }
  }

  vcPri.reserve(vcPri.size() + vcTab.size());
  vcPri.insert(vcPri.end(), vcTab.begin(), vcTab.end());
  return vcPri;
}

// 素数列挙Primes(n)のグローバルリスト化
// デフォルトのサイズは0
std::vector<lnt> vcPRIMES_PREPARED = Primes(0);

//素数列挙Primes(n)のグローバルリスト化におけるリストサイズ指定関数
inline void SPECIFY_LISTSIZE_PRIMES(const lnt max_size) {
  vcPRIMES_PREPARED = Primes(max_size);
}

// 素因数分解:PrimeDecomp(n)
// 2番目の引数にはPrimes(k) (kは十分大 >= floor(sqrt(n))) を入れる
MAP<lnt, lnt>
PrimeDecomp(const lnt n,
            const std::vector<lnt> &vcPrimesRoot_n = vcPRIMES_PREPARED) {
  if (n < 2) {
    return MAP<lnt, lnt>();
  }

  MAP<lnt, lnt> PrimeDecomp;

  lnt m = n;
  for (lnt p : vcPrimesRoot_n) {
    while (m % p == 0) {
      m /= p;
      if (PrimeDecomp.count(p)) {
        PrimeDecomp[p]++;
      } else {
        PrimeDecomp.emplace(p, 1);
      }
    }
  }
  if (m != 1) {
    PrimeDecomp.emplace(m, 1);
  }
  if (vcPrimesRoot_n.empty()) {
    std::cout << "Warning! The SPECIFY_LISTSIZE_PRIMES function is not called."
              << "\n";
  }
  return PrimeDecomp;
}

// 約数列挙:Divisors(n)
// 2番目の引数にはPrimes(k) (kは十分大 >= floor(sqrt(n))) を入れる
std::vector<lnt>
Divisors(const lnt n,
         const std::vector<lnt> &vcPrimesRoot_n = vcPRIMES_PREPARED) {
  std::vector<lnt> vcDiv(1, 1), vcTable;
  auto mpPD = PrimeDecomp(n, vcPrimesRoot_n);
  for (auto itrPD = mpPD.begin(); itrPD != mpPD.end(); itrPD++) {
    lnt nPri = itrPD->first, nMulti = itrPD->second;
    vcTable.resize(vcDiv.size() * (nMulti + 1));
    for (lnt i = 0; i < nMulti + 1; i++) {
      std::transform(vcDiv.begin(), vcDiv.end(),
                     vcTable.begin() + (i * vcDiv.size()),
                     [nPri, i](lnt x) { return x * pow(nPri, i); });
    }
    vcDiv = vcTable;
  }
  std::sort(vcDiv.begin(), vcDiv.end());
  if (vcPrimesRoot_n.empty()) {
    std::cout << "Warning! The SPECIFY_LISTSIZE_PRIMES function is not called."
              << "\n";
  }
  return vcDiv;
}

//最大公約数:gcd(n, m) (gcd(0, 0)=0)
lnt GCD(const lnt n, const lnt m) {
  if (!n || !m) {
    return MAX(n, m);
  }
  lnt nDivided = MAX(n, m), nDividing = MIN(n, m);
  while (nDivided % nDividing) {
    nDivided = nDivided % nDividing;
    std::swap(nDivided, nDividing);
  }
  return nDividing;
}

//最小公倍数:lcm(n, m)
lnt LCM(const lnt n, const lnt m) {
  if (!n && !m) {
    return 0;
  }
  return n / GCD(n, m) * m;
}

// mod2乘
lnt inline SQ(const lnt n, const lnt mod = MOD) {
  return ((n % mod) * (n % mod)) % mod;
}

// mod冪乗
lnt POW(const lnt x, const lnt y, const lnt mod = MOD) {
  if (x >= 0 and y >= 0) {
    if (y == 0) {
      return 1 % mod;
    }
    if (y == 1) {
      return x % mod;
    }
    if (y % 2 == 0) {
      return SQ(POW(x, y / 2, mod), mod);
    }
    return SQ(POW(x, y / 2, mod), mod) * (x % mod) % mod;
  }
  std::cout << "Warning!"
            << "\n";
  return 0;
}

// mod 2の冪
lnt inline BIT(const lnt i) {
  if (i >= 0) {
    return POW(2, i);
  }
  std::cout << "Warning!"
            << "\n";
  return 0;
}

// long long まで許すSQ
lnt inline LSQ(const lnt n) { return n * n; }

// long long まで許すPOW
lnt LPOW(const lnt x, const lnt y) {
  if (x >= 0 and y >= 0) {
    if (y == 0) {
      return 1;
    }
    if (y == 1) {
      return x;
    }
    if (y % 2 == 0) {
      return LSQ(LPOW(x, y / 2));
    }
    return LSQ(LPOW(x, y / 2)) * x;
  }
  std::cout << "Warning!"
            << "\n";
  return 0;
}

// long longまで許すBIT
lnt inline LBIT(const lnt i) {
  if (i >= 0) {
    return LPOW(2, i);
  }
  std::cout << "Warning!"
            << "\n";
  return 0;
}

// n以下の階乗/mod階乗のリストを生成　
std::vector<lnt> vcFACT(const lnt n, const lnt mod = MOD) {
  if (n >= 0) {
    std::vector<lnt> vcFact = {1 % mod};
    lnt fact = 1 % mod;
    FOR(k, 1, n + 1) {
      fact = (fact * (k % mod)) % mod;
      vcFact.push_back(fact);
    }
    return vcFact;
  }
  std::cout << "Warning!　The 1st argument is negative!"
            << "\n";
  return std::vector<lnt>(0);
}

// n以下のmod階乗の逆元のリストを生成(mod:素数を想定)
std::vector<lnt> vcINVFACT(const lnt n, const lnt mod = MOD) {
  std::vector<lnt> vcInvFact;
  lnt invfact = POW(vcFACT(n, mod).at(n), mod - 2, mod);
  vcInvFact.push_back(invfact);
  INVFOR(k, 1, n + 1) {
    invfact = invfact * (k % mod) % mod;
    vcInvFact.push_back(invfact);
  }
  std::reverse(ALL(vcInvFact));
  return vcInvFact;
}

// mod階乗のリストvcFACT(n, MOD)，mod階乗の逆元リストvcINVFACT(n, MOD)の
//グローバルリスト化 デフォルトのサイズは0
std::vector<lnt> vcMODFACT_PREPARED = vcFACT(0, MOD);
std::vector<lnt> vcMODINVFACT_PREPARED = vcINVFACT(0, MOD);

// mod階乗リストvcFACT(n, MOD)，mod階乗の逆元リストvcINVFACT(n, MOD)の，
// グローバルリスト化におけるリストサイズ指定関数
inline void SPECIFY_LISTSIZE_MODFACT(const lnt max_size) {
  vcMODFACT_PREPARED = vcFACT(max_size, MOD);
}
inline void SPECIFY_LISTSIZE_MODINVFACT(const lnt max_size) {
  vcMODINVFACT_PREPARED = vcINVFACT(max_size, MOD);
}

// 階乗
// mod > 0．3番目の引数にはvcFACT(m, mod)を入れる
// (m >= n:十分大)
lnt inline FACT(const lnt n, const lnt mod = MOD,
                const std::vector<lnt> &vcModFact = vcMODFACT_PREPARED) {
  if (vcModFact.empty()) {
    std::cout << "Warning! The SPECIFY_LISTSIZE_PRIMES function"
              << " has not been called."
              << "\n";
  }

  return vcModFact.at(n);
}

// 順列の数
// mod:素数を想定．4, 5番目の引数にはvcFACT(m1, mod)，vcINVFACT(m2, mod)を入れる
// (m1 >= n, m2 >= n-k :十分大)
lnt PERM(const lnt n, const lnt k, const lnt mod = MOD,
         const std::vector<lnt> &vcModFact = vcMODFACT_PREPARED,
         const std::vector<lnt> &vcModInvFact = vcMODINVFACT_PREPARED) {
  if (k >= 0) {
    return vcModFact.at(n) * vcModInvFact.at(n - k) % mod;
  }
  std::cout << "Warning!"
            << "\n";
  std::cout << "Note that 4th, 5th argument : vcFact(m1, mod), vcFact(m2, mod)."
            << "\n";
  if (vcModFact.empty()) {
    std::cout << "Warning! The SPECIFY_LISTSIZE_PRIMES function is not called."
              << "\n";
  }
  if (vcModInvFact.empty()) {
    std::cout << "Warning! The SPECIFY_LISTSIZE_PRIMES function is not called."
              << "\n";
  }

  return 0;
}

//二項係数
// mod:素数を想定．4, 5番目の引数にはvcFACT(m1, mod)，vcINVFACT(m2, mod)を入れる
// (m1 >= n, m2 >= n-k, k :十分大)
lnt inline COMB(const lnt n, const lnt k, const lnt mod = MOD,
                const std::vector<lnt> &vcModFact = vcMODFACT_PREPARED,
                const std::vector<lnt> &vcModInvFact = vcMODINVFACT_PREPARED) {
  return PERM(n, k, mod, vcModFact, vcModInvFact) * vcModInvFact.at(k) % mod;
}

//重複組み合わせの数
// mod:素数を想定．4, 5番目の引数にはvcFACT(m1, mod)，vcINVFACT(m2,mod)を入れる
// (m1 >= n+k-1, m2 >= n-1, k :十分大)
lnt inline HCOMB(const lnt n, const lnt k, const lnt mod = MOD,
                 const std::vector<lnt> &vcModFact = vcMODFACT_PREPARED,
                 const std::vector<lnt> &vcModInvFact = vcMODINVFACT_PREPARED) {
  return COMB(n + k - 1, k, mod, vcModFact, vcModInvFact);
}

// 非負整数valueのbase進数表示でのposition桁目を表示
lnt inline MASK(const lnt value, const lnt position, const lnt base = 10) {
  if (value >= 0 and base >= 2) {
    return (value / LPOW(base, position)) % base;
  }
  std::cout << "WARNING! The MASK fucntion is applyed in a wrong manner."
            << "\n";
  return 0;
}

// ビットマスク
lnt inline BMASK(const lnt value, const lnt position) {
  return MASK(value, position, 2);
}

// MASKにおいて，position桁目に数字がない時0ではなくbaseを返す
lnt inline DIGIT(const lnt value, const lnt position, const lnt base = 10) {
  if (value >= 0 and base >= 2) {
    if (value == 0) {
      if (position == 0) {
        return 0;
      }
      return base;
    }
    if (value < LPOW(base, position)) {
      return base;
    }
    return MASK(value, position, base);
  }

  std::cout << "WARNING!"
            << "\n";
  return 0;
}

// base=2のDIGIT
lnt inline BDIGIT(const lnt value, const lnt position) {
  return DIGIT(value, position, 2);
}

typedef std::pair<lnt, lnt> P;

// ポテンシャル付きUnion-Find木
template <class T> class UnionFind {
private:
  MAP<T, T> par;
  MAP<T, lnt> rank;
  MAP<T, lnt> diff_from_par;
  MAP<T, lnt> sz;
  lnt nTree = 0;
  lnt weight(const T &);

public:
  UnionFind<T>();
  UnionFind<T>(const SET<T> &);
  T find(const T &);
  lnt diff(const T &, const T &);
  bool unite(const T &, const T &, const lnt = 0);
  bool equi(const T &x, const T &y) { return find(x) == find(y); }
  lnt size_at(const T &x) { return sz.at(find(x)); }
  lnt n_tree() const { return nTree; }
};

template <class T> UnionFind<T>::UnionFind(const SET<T> &st) {
  par.reserve(SIZE(st));
  rank.reserve(SIZE(st));
  diff_from_par.reserve(SIZE(st));
  sz.reserve(SIZE(st));
  for (T x : st) {
    par.emplace(x, x);
    rank.emplace(x, 0);
    diff_from_par.emplace(x, 0);
    sz.emplace(x, 1);
  }
  nTree = SIZE(st);
}

// 経路圧縮しながらrootを返す
template <class T> T UnionFind<T>::find(const T &x) {
  if (par.at(x) == x) {
    return x;
  }
  T root = find(par.at(x));
  diff_from_par.at(x) += diff_from_par.at(par.at(x));
  return par.at(x) = root;
}

// rootを基準としたポテンシャル
template <class T> lnt UnionFind<T>::weight(const T &x) {
  find(x);
  return diff_from_par.at(x);
}

// yを基準としたxのポテンシャルを返す
// 異なる木に対するdiff関数は意味を持たないので，警告も出力
template <class T> lnt UnionFind<T>::diff(const T &x, const T &y) {
  if (not equi(x, y)) {
    std::cout << "Warning! The roots of x and y are not same."
              << "\n";
  }
  return weight(x) - weight(y);
}

// diff(x, y) = w となるようにxのtreeとyのtreeを繋ぐ
// xのtreeとyのtreeが既に同じで，diff(x, y) ≠ w　なら何もせずにfalseを返す
template <class T>
bool UnionFind<T>::unite(const T &x, const T &y, const lnt w) {
  T p = find(x);
  T q = find(y);
  if (p == q) {
    if (diff(x, y) == w) {
      return true;
    }
    return false;
  }
  lnt v = w + weight(y) - weight(x);
  if (rank.at(p) > rank.at(q)) {
    std::swap(p, q);
    v = -v;
  }
  if (rank.at(p) == rank.at(q)) {
    rank.at(q)++;
  }
  par.at(p) = q;
  diff_from_par.at(p) = v;
  sz.at(q) += sz.at(p);
  nTree--;
  return true;
}

// UnionFind<lnt>
template <> class UnionFind<lnt> {
private:
  MAP<lnt, lnt> par;
  MAP<lnt, lnt> rank;
  MAP<lnt, lnt> diff_from_par;
  MAP<lnt, lnt> sz;
  lnt nTree = 0;
  lnt weight(const lnt);

public:
  UnionFind<lnt>();
  UnionFind<lnt>(const SET<lnt> &);
  UnionFind<lnt>(const lnt);
  lnt find(const lnt);
  lnt diff(const lnt, const lnt);
  bool unite(const lnt, const lnt, const lnt = 0);
  bool equi(const lnt x, const lnt y) { return find(x) == find(y); }
  lnt size_at(const lnt x) { return sz.at(find(x)); }
  lnt n_tree() const { return nTree; }
};

UnionFind<lnt>::UnionFind(const SET<lnt> &st) {
  par.reserve(SIZE(st));
  rank.reserve(SIZE(st));
  diff_from_par.reserve(SIZE(st));
  sz.reserve(SIZE(st));
  for (lnt x : st) {
    par.emplace(x, x);
    rank.emplace(x, 0);
    diff_from_par.emplace(x, 0);
    sz.emplace(x, 1);
  }
  nTree = SIZE(st);
}

UnionFind<lnt>::UnionFind(const lnt num) {
  par.reserve(num);
  rank.reserve(num);
  diff_from_par.reserve(num);
  sz.reserve(num);
  REP(i, num) {
    par.emplace(i, i);
    rank.emplace(i, 0);
    diff_from_par.emplace(i, 0);
    sz.emplace(i, 1);
  }
  nTree = num;
}

// 経路圧縮しながらrootを返す
lnt UnionFind<lnt>::find(const lnt x) {
  if (par.at(x) == x) {
    return x;
  }
  lnt root = find(par.at(x));
  diff_from_par.at(x) += diff_from_par.at(par.at(x));
  return par.at(x) = root;
}

// rootを基準としたポテンシャル
lnt UnionFind<lnt>::weight(const lnt x) {
  find(x);
  return diff_from_par.at(x);
}

// yを基準としたxのポテンシャルを返す
// 異なる木に対するdiff関数は意味を持たないので，警告も出力
lnt UnionFind<lnt>::diff(const lnt x, const lnt y) {
  if (not equi(x, y)) {
    std::cout << "Warning! The roots of x and y are not same."
              << "\n";
  }
  return weight(x) - weight(y);
}

// diff(x, y) = w となるようにxのtreeとyのtreeを繋ぐ
// xのtreeとyのtreeが既に同じで，diff(x, y) ≠ w　なら何もせずにfalseを返す
bool UnionFind<lnt>::unite(const lnt x, const lnt y, const lnt w) {
  lnt p = find(x);
  lnt q = find(y);
  if (p == q) {
    if (diff(x, y) == w) {
      return true;
    }
    return false;
  }
  lnt v = w + weight(y) - weight(x);
  if (rank.at(p) > rank.at(q)) {
    std::swap(p, q);
    v = -v;
  }
  if (rank.at(p) == rank.at(q)) {
    rank.at(q)++;
  }
  par.at(p) = q;
  diff_from_par.at(p) = v;
  sz.at(q) += sz.at(p);
  nTree--;
  return true;
}

using namespace std;

lnt PAIR(const lnt &x0, const lnt &N) {
  lnt x = x0;
  vector<lnt> tri;
  LOOP(N) {
    tri.push_back(x % 3);
    x /= 3;
  }

  lnt y = 0;
  INVREP(j, N) {
    y *= 3;
    y += (3 - tri.at(j)) % 3;
  }
  return y;
}

MAIN() {
  lnt A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  if (A + B <= 2 * C) {
    cout << X * A + Y * B << endl;
    return 0;
  }

  //以下, A + B > 2 * Cが担保される.

  lnt max = MAX(X, Y);
  lnt min = MIN(X, Y);

  lnt cst = min * 2 * C;
  if (max == min) {
    cout << cst << endl;
    return 0;
  }

  //以下, X != Yが担保される.

  cout << (X > Y ? cst + MIN(2*C, A) * (X-Y) : cst + MIN(2*C, B) * (Y-X))
       << endl;
}
