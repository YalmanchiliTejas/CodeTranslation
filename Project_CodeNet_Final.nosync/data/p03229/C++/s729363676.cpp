//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <cctype>
#include <complex>
#include <regex>


using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VLL> VVLL;
typedef vector<VVI> VVVI;
typedef vector<VVLL> VVVLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<VPII> VVPII;
typedef vector<VPLL> VVPLL;
typedef vector<VS> VVS;

//数値・文字列
//------------------------------------------
inline int toInt(string s) {
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

inline LL toLongLong(string s) {
    LL v;
    istringstream sin(s);
    sin >> v;
    return v;
}

template<class T>
inline string toString(T x) {
    ostringstream sout;
    sout << x;
    return sout.str();
}

inline VC toVC(string s) {
    VC data(s.begin(), s.end());
    return data;
}

template<typename List>
void SPRIT(const std::string &s, const std::string &delim, List &result) {
    result.clear();
    string::size_type pos = 0;
    while (pos != string::npos) {
        string::size_type p = s.find(delim, pos);
        if (p == string::npos) {
            result.push_back(s.substr(pos));
            break;
        } else {
            result.push_back(s.substr(pos, p - pos));
        }
        pos = p + delim.size();
    }
}

string TRIM(const string &str, const char *trimCharacterList = " \t\v\r\n") {
    string result;
    string::size_type left = str.find_first_not_of(trimCharacterList);
    if (left != string::npos) {
        string::size_type right = str.find_last_not_of(trimCharacterList);
        result = str.substr(left, right - left + 1);
    }
    return result;
}

string REPLACE_STRING(const string source, const string find, const string alt) {
    string result = source;
    string::size_type pos = 0;
    while (pos = result.find(find, pos), pos != string::npos) {
        result.replace(pos, find.length(), alt);
        pos += alt.length();
    }
    return result;
}

template<typename T>
bool VECTOR_EXISTS(vector<T> vec, T data) {
    auto itr = std::find(vec.begin(), vec.end(), data);
    size_t index = distance(vec.begin(), itr);
    if (index != vec.size())return true;
    else return false;
}

template<typename T>
vector<T> VECTOR_UNIQUE_ERASE(vector<T> vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template<typename T>
void VECTOR_REMOVE_VALUE_ALL(vector<T> &vec, T data) {
    vec.erase(remove(vec.begin(), vec.end(), data), vec.end());
}

template<typename T>
vector<T> VECTOR_REMOVE_VALUE_ALL_FAST(vector<T> vec, T data) {
    vector<T> vec2;
    for (auto &x: vec) if (x != data) vec2.push_back(x);
    return vec2;
}

bool REG_MATCH(string const &text, regex const &re) {
    bool result = regex_match(text, re);
    return result;
}

bool REG_MATCH(string const &text, smatch &match, regex const &re) {
    bool result = regex_match(text, match, re);
    return result;
}

smatch REG_SEARCH(string const &text, regex const &re) {
    smatch m;
    regex_search(text, m, re);
    return m;
}

vector<smatch> REG_ALL_SEARCH(string const &text, regex const &re) {
    vector<smatch> matchs;
    sregex_iterator iter(text.cbegin(), text.cend(), re);
    sregex_iterator end;
    for (; iter != end; iter++) matchs.push_back(*iter);
    return matchs;
}

string REG_REPLACE(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace, regex_constants::format_first_only);
    return result;
}

string REG_ALL_REPLACE(string const &text, regex const &re, string const &replace) {
    string result = regex_replace(text, re, replace);
    return result;
}

#define UPPER(s) transform((s).begin(), (s).end(), (s).begin(), ::toupper)
#define LOWER(s) transform((s).begin(), (s).end(), (s).begin(), ::tolower)



//四捨五入 nLen=小数点第n位にする
//------------------------------------------

//切り上げ
double ceil_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (int) (dOut + 0.9);
    return dOut * pow(10.0, -nLen);
}

//切り捨て
double floor_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (int) (dOut);
    return dOut * pow(10.0, -nLen);
}

//四捨五入
double round_n(double dIn, int nLen) {
    double dOut;
    dOut = dIn * pow(10.0, nLen);
    dOut = (double) (int) (dOut + 0.5);
    return dOut * pow(10.0, -nLen);
}

//n桁目の数の取得
int take_a_n(LL num, int n) {
    string str = toString(num);
    return str[str.length() - n] - '0';
}


//進数
//------------------------------------------

//"1111011" → 123
int strbase_2to10(const std::string &s) {
    int out = 0;
    for (int i = 0, size = s.size(); i < size; ++i) {
        out *= 2;
        out += ((int) s[i] == 49) ? 1 : 0;
    }
    return out;
}

//"123" → 1111011
int strbase_10to2(const std::string &s) {
    int binary = toInt(s);
    int out = 0;
    for (int i = 0; binary > 0; i++) {
        out = out + (binary % 2) * pow(static_cast<int>(10), i);
        binary = binary / 2;
    }
    return out;
}

//"ABC" 2748
int strbase_16to10(const std::string &s) {
    int out = stoi(s, 0, 16);
    return out;
}

//1111011 → 123
int intbase_2to10(int in) {
    string str = toString(in);
    return strbase_2to10(str);
}

//123 → 1111011
int intbase_10to2(int in) {
    string str = toString(in);
    return strbase_10to2(str);
}

int intbase_16to10(int in) {
    string str = toString(in);
    return strbase_16to10(str);
}

//123→ "7B"
string intbase_10to16(unsigned int val, bool lower = true) {
    if (!val)
        return std::string("0");
    std::string str;
    const char hc = lower ? 'a' : 'A';     // 小文字 or 大文字表記
    while (val != 0) {
        int d = val & 15;     // 16進数一桁を取得
        if (d < 10)
            str.insert(str.begin(), d + '0');  //  10未満の場合
        else //  10以上の場合
            str.insert(str.begin(), d - 10 + hc);
        val >>= 4;
    }
    return str;
}

//整数を2進数表記したときの1の個数を返す
LL bitcount64(LL bits) {
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    return (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
}



//comparison
//------------------------------------------
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define C_MIN(a, b) ((a)<(b)?(a):(b))
#define C_ABS(a, b) ((a)<(b)?(b)-(a):(a)-(b))

template<typename T1, typename T2>
inline void S_MAX(T1 &a, T2 b) { a = C_MAX(a, b); };

template<typename T1, typename T2>
inline void S_MIN(T1 &a, T2 b) { a = C_MIN(a, b); };


//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EACH(i, arr) for(typeof((arr).begin()) i=(arr).begin(); i!=(arr).end(); ++i)
#define EXIST(str, e) ((str).find(e)!=(str).end())
#define COUNT(arr, v) count((arr).begin(), (arr).end(), v)
#define SEARCH(v, w) search((v).begin(), (v).end(), (w).begin(), (w).end())
#define B_SEARCH(arr, v) binary_search((arr).begin(), (arr).end(), v)
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define ROTATE_LEFT(arr, c) rotate((arr).begin(), (arr).begin()+(c), (arr).end())
#define ROTATE_RIGHT(arr, c) rotate((arr).rbegin(), (arr).rbegin() + (c), (arr).rend())
#define SUMI(arr) accumulate((arr).begin(), (arr).end(), 0)
#define SUMD(arr) accumulate((arr).begin(), (arr).end(), 0.)
#define SUMLL(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#define SUMS(arr) accumulate((arr).begin(), (arr).end(), string())
#define UB(arr, n) upper_bound((arr).begin(), (arr).end(), n)
#define LB(arr, n) lower_bound((arr).begin(), (arr).end(), n)
#define OF_ALL(arr, func) all_of((arr).begin(), (arr).end(), (func))
#define OF_NONE(arr, func) none_of((arr).begin(), (arr).end(), (func))
#define OF_ANY(arr, func) any_of((arr).begin(), (arr).end(), (func))
#define PB push_back
#define MP make_pair




//input output
//------------------------------------------
#define GL(s) getline(cin, (s))
#define INIT() std::ios::sync_with_stdio(false);std::cin.tie(0);
#define OUT(d) std::cout<<(d)
#define OUT_L(d) std::cout<<(d)<<endl
#define FOUT(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)
#define FOUT_L(n, data) std::cout<<std::fixed<<std::setprecision(n)<<(data)<<"\n"
#define EL() printf("\n")
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v) {std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define YES() printf("YES\n")
#define NO() printf("NO\n")


template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
    in >> p.first >> p.second;
    return in;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v)
        in >> x;
    return in;
}




//repetition
//------------------------------------------
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n)  FOR(i,0,n)
#define RREP(i, n) for(int i = n-1;i >= 0;i--)
#define FORLL(i, a, b) for(LL i=LL(a);i<LL(b);++i)
#define RFORLL(i, a, b) for(LL i=LL(b)-1;i>=LL(a);--i)
#define REPLL(i, n) for(LL i=0;i<LL(n);++i)
#define RREPLL(i, n) for(LL i=LL(n)-1;i>=0;--i)
#define FOREACH(x, arr) for(auto &(x) : (arr))
#define FORITER(x, arr) for(auto (x) = (arr).begin(); (x) != (arr).end(); ++(x))


//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};


//math
//--------------------------------------------

//min <= aim <= max
template<typename T>
inline bool BETWEEN(const T aim, const T min, const T max) {
    if (min <= aim && aim <= max) {
        return true;
    } else {
        return false;
    }
}


template<class T>
inline T SQR(const T x) { return x * x; }

template<class T1, class T2>
inline T1 POW(const T1 x, const T2 y) {
    if (!y)return 1;
    else if ((y & 1) == 0) {
        return SQR(POW(x, y >> 1));
    } else return POW(x, y ^ 1) * x;
}


template<typename T>
constexpr T ABS(T x) {
    return x < 0 ? -x : x;
}

//partial_permutation nPr 順列
//first・・最初の数
//middle・・r(取り出す数)
//last・・n(全体数)
template<class Iter>
bool next_partial_permutation(Iter first, Iter middle, Iter last) {
    reverse(middle, last);
    return next_permutation(first, last);
}

//combination nCr 組み合わせ
//first1・・最初の数
//last1==first2・・r(取り出す数)
//last2・・n(全体数)
template<class Iter>
bool next_combination(Iter first1, Iter last1, Iter first2,
                      Iter last2) {
    if ((first1 == last1) || (first2 == last2)) {
        return false;
    }
    Iter m1 = last1;
    Iter m2 = last2;
    --m2;
    while (--m1 != first1 && !(*m1 < *m2)) {
    }
    bool result = (m1 == first1) && !(*first1 < *m2);
    if (!result) {
        while (first2 != m2 && !(*m1 < *first2)) {
            ++first2;
        }
        first1 = m1;
        std::iter_swap(first1, first2);
        ++first1;
        ++first2;
    }
    if ((first1 != last1) && (first2 != last2)) {
        m1 = last1;
        m2 = first2;
        while ((m1 != first1) && (m2 != last2)) {
            std::iter_swap(--m1, m2);
            ++m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return !result;
}




//numeric_law
//--------------------------------------------

template<typename T>
constexpr bool ODD(T x) {
    return x % 2 != 0;
}

template<typename T>
constexpr bool EVEN(T x) {
    return x % 2 == 0;
}

//最大公約数
template<class T>
inline T GCD(const T x, const T y) {
    if (x < 0)return GCD(-x, y);
    if (y < 0)return GCD(x, -y);
    return (!y) ? x : GCD(y, x % y);
}

//最小公倍数
template<class T>
inline T LCM(const T x, const T y) {
    if (x < 0)return LCM(-x, y);
    if (y < 0)return LCM(x, -y);
    return x * (y / GCD(x, y));
}

//ax + by = 1
//x,yが変数に格納される
template<class T>
inline T EXTGCD(const T a, const T b, T &x, T &y) {
    if (a < 0) {
        T d = EXTGCD(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = EXTGCD(a, -b, x, y);
        y = -y;
        return d;
    }
    if (!b) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = EXTGCD(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}

//素数
template<class T>
inline bool ISPRIME(const T x) {
    if (x <= 1)return false;
    for (T i = 2; SQR(i) <= x; i++)if (x % i == 0)return false;
    return true;
}

//素数をtrueとして返す
template<class T>
VB ERATOSTHENES(const T n) {
    VB arr(n, true);
    for (int i = 2; SQR(i) < n; i++) {
        if (arr[i]) {
            for (int j = 0; i * (j + 2) < n; j++) {
                arr[i * (j + 2)] = false;
            }
        }
    }
    return arr;
}

// a <= x < b の素数を返す
template<typename T>
VB ERATOSTHENES(const T a, const T b) {
    VB small = ERATOSTHENES(b);
    VB prime(b - a, true);

    for (int i = 2; (T) (SQR(i)) < b; i++) {
        if (small[i]) {
            for (T j = max(2, (a + i - 1) / i) * i; j < b; j += i) {
                prime[j - a] = false;
            }
        }
    }

    return prime;
}

//nの約数
template<typename T>
vector<T> DIVISOR(T n) {
    vector<T> v;
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

//nまでのすべての約数
template<typename T>
vector<vector<T>> DIVISOR_ALL(T n) {
    vector<vector<T>> res(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            res[j].push_back(i);
        }
    }
    return res;
}

//素因数分解
template<typename T>
vector<pair<T, LL>> FACTORIZATION(T x) {
    vector<pair<T, LL>> ans;
    for (T i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            LL count = 0;
            while (x % i == 0) {
                count++;
                x /= i;
            }
            ans.push_back(MP(i, count));
        }
    }
    if (x != 1) ans.push_back(MP(x, 1));
    return ans;
}

//N^P (mod M)
LL POW_MOD(LL N, LL P, LL M) {
    if (P == 0) return 1LL;
    if (P % 2 == 0) {
        LL ret = POW_MOD(N, P / 2, M);
        return ret * ret % M;
    }
    return N * POW_MOD(N, P - 1, M) % M;
}

//組み合わせ個数
template<typename T>
inline T NCR(T n, T r) {
    T ans = 1;
    REPLL(i, r) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

//組み合わせ個数 (mod M)
LL NCR_MOD(LL n, LL r, LL M) {
    if (r > n - r) return NCR_MOD(n, n - r, M);
    LL numerator = 1LL; //分子
    LL denominator = 1LL; //分母
    for (LL i = 0; i < r; i++) {
        numerator *= (n - i);
        numerator %= M;
        denominator *= (i + 1);
        denominator %= M;
    }
    return numerator * POW_MOD(denominator, M - 2, M) % M;
}

//confirmation
//--------------------------------------------

//clear memory
#define CLR(arr, d) memset((arr), (d),sizeof(arr))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


/*
 *
 *
 *   ~~~~Below My Answer~~~~
 *
 *
 */

//int main() {
//
//    LL N;
//    cin >> N;
//
//    while (true) {
//        std::mt19937 mt{std::random_device{}()};
//        std::uniform_int_distribution<int> dist(1, 10);
//
//        VLL A(N);
//        for (int i = 0; i < N; i++) A[i] = dist(mt);
//        SORT(A);
//
//        VLL low((N + 1) / 2);
//        VLL high(N - (N + 1) / 2);
//        for (int i = 0; i < low.size(); i++) low[i] = A[i];
//        for (int i = 0; i < high.size(); i++) high[i] = A[i + low.size()];
//        RSORT(high);
//
//        int l = 0;
//        int h = 0;
//        list<LL> L;
//        L.push_front(low[l++]);
//        if (N % 4 == 3) {
//            for (int i = 0; i < N; i++) {
//                if (h < high.size())L.push_front(high[h++]);
//                if (h < high.size())L.push_back(high[h++]);
//                if (i == N / 4) {
//                    if (l < low.size())L.push_back(low[l++]);
//                    if (l < low.size()) L.push_back(low[l++]);
//                } else {
//                    if (l < low.size())L.push_front(low[l++]);
//                    if (l < low.size()) L.push_back(low[l++]);
//                }
//
//            }
//        } else {
//            for (int i = 0; i < N; i++) {
//                if (h < high.size())L.push_front(high[h++]);
//                if (h < high.size())L.push_back(high[h++]);
//                if (l < low.size())L.push_front(low[l++]);
//                if (l < low.size()) L.push_back(low[l++]);
//            }
//        }
//
//        LL ans = 0;
//        vector<LL> v;
//        for (auto x: L) v.push_back(x);
//
//        for (int i = 0; i < v.size() - 1; i++) ans += ABS(v[i + 1] - v[i]);
//
//        LL ansMAX = LONG_LONG_MIN;
//        do {
//            LL a = 0;
//            for (int i = 0; i < N - 1; i++) a += ABS(A[i + 1] - A[i]);
//            S_MAX(ansMAX, a);
//        } while (next_permutation(ALL(A)));
//
//        if (ansMAX != ans) {
//            cout << ansMAX << " " << ans << endl;
//            for (int i = 0; i < A.size(); i++) cout << A[i] << " ";
//            break;
//        }
//    }
//
//    return 0;
//}




int main() {

    LL N;
    cin >> N;

    VLL A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    SORT(A);

    VLL low((N + 1) / 2);
    VLL high(N - (N + 1) / 2);

    for (int i = 0; i < low.size(); i++) low[i] = A[i];
    for (int i = 0; i < high.size(); i++) high[i] = A[i + low.size()];

    SHOW_VECTOR(low);
    SHOW_VECTOR(high);
    RSORT(high);

    int l = 0;
    int h = 0;
    list<LL> L;
    list<LL> L2;
    L.push_front(low[l++]);
    if (N % 4 == 3) {
        for (int i = 0; i < N; i++) {
            if (h < high.size())L.push_front(high[h++]);
            if (h < high.size())L.push_back(high[h++]);
            if (i == N / 4) {
                if (l < low.size())L.push_back(low[l++]);
                if (l < low.size()) L.push_back(low[l++]);
            } else {
                if (l < low.size())L.push_front(low[l++]);
                if (l < low.size()) L.push_back(low[l++]);
            }

        }
    } else {
        for (int i = 0; i < N; i++) {
            if (h < high.size())L.push_front(high[h++]);
            if (h < high.size())L.push_back(high[h++]);
            if (l < low.size())L.push_front(low[l++]);
            if (l < low.size()) L.push_back(low[l++]);
        }
    }

    if (N % 2 == 1) {
        l = 0, h = 0;
        swap(low, high);
        L2.push_front(low[l++]);
        if (N % 4 == 1) {
            for (int i = 0; i < N; i++) {
                if (N / 4 == i) {
                    if (h < high.size())L2.push_back(high[h++]);
                    if (h < high.size())L2.push_back(high[h++]);
                } else {
                    if (h < high.size())L2.push_front(high[h++]);
                    if (h < high.size())L2.push_back(high[h++]);
                }
                if (l < low.size())L2.push_front(low[l++]);
                if (l < low.size()) L2.push_back(low[l++]);
            }
        } else {
            for (int i = 0; i < N; i++) {
                if (h < high.size())L2.push_front(high[h++]);
                if (h < high.size())L2.push_back(high[h++]);
                if (l < low.size())L2.push_front(low[l++]);
                if (l < low.size()) L2.push_back(low[l++]);
            }
        }
    }

    LL ans = 0;
    vector<LL> v;
    for (auto x: L) v.push_back(x);

    vector<LL> v2;
    LL ans2 = 0;
    for (auto x: L2) v2.push_back(x);

    for (int i = 0; i < v.size() - 1; i++) ans += ABS(v[i + 1] - v[i]);
    if (v2.size() > 0)
        for (int i = 0; i < v2.size() - 1; i++) ans2 += ABS(v2[i + 1] - v2[i]);

    cout << max(ans, ans2) << endl;

    return 0;
}













































