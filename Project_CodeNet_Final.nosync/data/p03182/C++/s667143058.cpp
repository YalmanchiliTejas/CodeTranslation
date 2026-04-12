#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i32 = int32_t;
using i64 = int64_t;
constexpr char newl = '\n';

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define F first
//#define S second
#define debug(x) cout << #x << ": " << x << '\n';
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1


template<class Element, class Lazy>
class SegmentTree {

  using A = function<Element(const Element&, const Element&)>;
  using B = function<void(Element&, const Lazy&, int elementCount)>;
  using C = function<void(Lazy&, const Lazy&)>;

  using ECallback = function<void(const Element&, const Lazy&)>;

  // index -> parent index
  constexpr int parent(int v) {
    return ((v + 1) >> 1) - 1;
  }
  constexpr bool hasChild(int v) {
    return v <= size - 2;
  }
  constexpr int lchild(int v) {
    return ((v + 1) << 1) - 1;
  }
  constexpr int rchild(int v) {
    return (v + 1) << 1;
  }

public:

  SegmentTree(int size, A mergeElements, B applyLazyToElement, C mergeLazies) :
  mergeTT(mergeElements), mergeTE(applyLazyToElement), mergeEE(mergeLazies) {

    int n = 1;
    while (n < size) n <<= 1;

    this->size = n;

    int segCount = n * 2 - 1;

    es = vector<Element>(segCount);

    ls = vector<Lazy>(segCount);

    lazyFlag = vector<bool>(segCount, false);

    lefts = vector<int>(segCount);
    rights = vector<int>(segCount);
    mp = vector<int>(segCount);

    for (int i = 0, l = 0, w = n; i < segCount; i++) {
      lefts[i] = l;
      rights[i] = lefts[i] + w;
      mp[i] = lefts[i] + (w >> 1);

      if (rights[i] >= n) {
        w >>= 1; l = 0;
      }
      else {
        l += w;
      }
    }
  }

  void Set(const Lazy& value, int left, int right, int segIndex = 0) {

    //cout << "Set " << "[" << left << ", " << right << ") si=" << segIndex << newl;

    if (left <= lefts[segIndex] && rights[segIndex] <= right) {
      add(segIndex, value);
      resolve(segIndex);
    }
    else {
      resolve(segIndex);

      auto l = lchild(segIndex), r = rchild(segIndex);
      if (left < mp[segIndex]) {
        Set(value, left, right, l);
      }
      else {
        resolve(l);
      }
      if (mp[segIndex] < right) {
        Set(value, left, right, r);
      }
      else {
        resolve(r);
      }

      es[segIndex] = mergeTT(es[l], es[r]);
    }
  }

  Element Get(int left, int right, int segIndex = 0) {

    if (right <= left) return Element();

    resolve(segIndex);
    if (left <= lefts[segIndex] && rights[segIndex] <= right) {
      return es[segIndex];
    }
    else {
      if (left < mp[segIndex]) {
        if (mp[segIndex] < right) {
          return mergeTT(Get(left, right, lchild(segIndex)), Get(left, right, rchild(segIndex)));
        }
        return Get(left, right, lchild(segIndex));
      }
      else if (mp[segIndex] < right) {
        return Get(left, right, rchild(segIndex));
      }
    }
  }

  void Print(ECallback c) {
    F0R(i, es.size()) {
      c(es[i], ls[i]);

      if (((i + 2) & (i + 1)) == 0) {
        cout << "." << newl;
      }
    }
  }

protected:

  void resolve(int segIndex) {
    if (!lazyFlag[segIndex]) return;

    mergeTE(es[segIndex], ls[segIndex], rights[segIndex] - lefts[segIndex]);

    if (hasChild(segIndex)) {
      auto l = lchild(segIndex), r = rchild(segIndex);
      add(l, ls[segIndex]);
      add(r, ls[segIndex]);
    }

    ls[segIndex] = Lazy();
    lazyFlag[segIndex] = false;
  }

  // 遅延データを追加
  void add(int segIndex, const Lazy& value) {

    if (lazyFlag[segIndex]) {
      mergeEE(ls[segIndex], value);
    }
    else {
      //cout << "set index" << segIndex << newl;
      ls[segIndex] = value;
      lazyFlag[segIndex] = true;
    }
  }

  A mergeTT;
  B mergeTE;
  C mergeEE;

  // 要素ごとのデータ
  vector<Element> es;

  // 要素ごとの遅延データ
  vector<Lazy> ls;

  // 遅延データがあるか
  vector<bool> lazyFlag;

  // 区間 [l, r) とその中間
  vector<int> lefts, rights, mp;

  // 区間のサイズ = 子を持たないエレメント数
  int size;
};


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);


  struct STE {
    i64 Max = 0, Sum = 0;
  };
  struct STL {
    i64 Set = 0, Add = 0;
  };

  auto c1 = [](const STE& l, const STE& r) -> STE {
    STE o;
    o.Max = max(l.Max, r.Max);
    o.Sum = l.Sum + r.Sum;
    return o;
  };
  auto c2 = [](STE& l, const STL& r, int elementCount) -> void {
    if (r.Add) {
      l.Max += r.Add;
      l.Sum += r.Add * elementCount;
    }
    if (r.Set) {
      l.Max = r.Set;
      l.Sum = r.Set;
    }
    //cout << "TE " << r.Add << " " << r.Set << newl;
  };
  auto c3 = [](STL& l, const STL& r) -> void {
    if (r.Set) {
      l.Add = 0;
      l.Set = r.Set;
    }
    else if (l.Set) {
      l.Set += r.Add;
    }
    else {
      l.Add += r.Add;
    }
  };
  auto qSet = [](i64 value) -> STL {
    STL l;
    l.Set = value;
    return l;
  };
  auto qAdd = [](i64 value) -> STL {
    STL l;
    l.Add = value;
    //cout << "Add " << value << " ";
    return l;
  };
  auto stPrint = [](const STE& v, const STL& l)->void {
    cout << "max=" << v.Max << " sum=" << v.Sum << "(" << l.Set << " A" << l.Add << ")" << newl;
  };


  // Debug : Segment Tree
#if 0
  SegmentTree<STE, STL> st(8, c1, c2, c3);
  st.Set(qSet(1), 0, 1);
  st.Set(qSet(3), 1, 2);
  st.Set(qSet(2), 2, 3);
  st.Set(qSet(6), 3, 4);
  st.Set(qSet(5), 4, 5);
  st.Set(qSet(4), 5, 6);
  st.Set(qSet(7), 6, 7);
  st.Set(qSet(9), 7, 8);
  st.Print(stPrint);
  cout << "----------" << newl;

  st.Set(qAdd(3), 0, 5);
  st.Print(stPrint);
  cout << "----------" << newl;

  st.Set(qSet(10), 0, 1);
  st.Print(stPrint);
  cout << "----------" << newl;

  return 0;
#endif


  int N, M;
  cin >> N >> M;

  // sums[i][j] := j で始まり i で終わる区間のスコアの和
  //unordered_map<int, unordered_map<int, i64>> sums;

  // as[i] := i で終わる区間の l とスコア
  vector<vector<pair<int, int>>> as(N + 1);

  F0R(i, M) {
    int l, r, a;
    cin >> l >> r >> a;
    //l--; r--;

    //sums[r][l] += a;
    as[r].emplace_back(l, a);
  }

  // n 文字目まで処理するとき、スコアはn文字までに終わる区間のもののみ考える
  // dp[i][j] = i文字目まで決めたとき、最後の1がj文字目のときの最大スコア
  // dp[i-1][j] + j を含み i で終わる区間のスコアの和 (j < i)
  // max(dp[i-1][0] ~ dp[i-1][j]) + i で終わる区間のスコアの和 (j == i)

  // dp[i]だけ持てばいい。
  // j を含み i で終わる区間のスコアの和 = [j ~ i, i] のスコアの和
  // つまり毎回[0,i]から[i,i]まで順に計算するなら、和をとっていけばいいだけなんだけど
  // それだとO(N^2)

  // なので Segment Tree を使って条件(M個)ごとに区間add(O(logN))していく


  SegmentTree<STE, STL> dp(N + 1, c1, c2, c3);

  // debug
#if 0
  STL l;
  l.Add = 1;
  dp.Set(l, 0, 1);
  dp.Print([](const STE& v, const STL& l)->void {
    cout << "max=" << v.Max << " sum=" << v.Sum << "(" << l.Set << " A" << l.Add << ")" << newl;
    });
  return 0;
#endif
  
  FOR(i, 1, N + 1) {

    //debug(i);

    //cout << "Set " << dp.Get(0, i).Max << " to [" << i << ", " << (i + 1) << ")" << newl;
    dp.Set(qSet(dp.Get(0, i).Max), i, i + 1);

    for (auto p : as[i]) {
      //cout << "Add " << p.second << " to [" << p.first << ", " << (i + 1) << ")" << newl;
      dp.Set(qAdd(p.second), p.first, i + 1); // [L, R) なので i+1
    }

    if (0) {
      dp.Print(stPrint);
    }
  }
  cout << dp.Get(0, N + 1).Max;
}
#endif
