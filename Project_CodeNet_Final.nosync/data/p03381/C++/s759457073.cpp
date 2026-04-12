#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

#define debug(v) {printf("L%d %s > ",__LINE__,#v);cout<<(v)<<endl;}
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:(v)){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(remove_const<decltype(l)>::type cnt=0;(cnt)<(l);++(cnt))
#define rrepeat(cnt,l) for(auto cnt=(l)-1;0<=(cnt);--(cnt))
#define iterate(cnt,b,e) for(auto cnt=(b);(cnt)!=(e);++(cnt))
#define diterate(cnt,b,e) for(auto cnt=(b);(cnt)!=(e);--(cnt))
const ll MD = 1000000007ll; const long double PI = 3.1415926535897932384626433832795L;
template<typename T1, typename T2> inline void assert_equal(T1 expected, T2 actual) { if (!(expected == actual)) { cerr << "assertion fault: expected=" << expected << " actual=" << actual << endl; abort(); } }
template<typename T1, typename T2> inline void assert_less(T1 actual, T2 threshold) { if (!(actual < threshold)) { cerr << "assertion fault: " << actual << " < (const)" << threshold << endl; abort(); } }
template<typename T1, typename T2> inline void assert_eqless(T1 actual, T2 threshold) { if (!(actual <= threshold)) { cerr << "assertion fault: " << actual << " <= (const)" << threshold << endl; abort(); } }
template<typename T1, typename T2> inline ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << '(' << p.first << ':' << p.second << ')'; return o; }
template<typename Vec> inline ostream& _ostream_vecprint(ostream &o, const Vec& p) { o << '['; for (auto& e : p) o << e << ','; o << ']'; return o; }
template<typename T> inline ostream& operator<<(ostream& o, const vector<T>& v) { return _ostream_vecprint(o, v); }
template<typename T, size_t S> inline ostream& operator<<(ostream& o, const array<T, S>& v) { return _ostream_vecprint(o, v); }
template<typename T> inline T& maxset(T& to, const T& val) { return to = max(to, val); }
template<typename T> inline T& minset(T& to, const T& val) { return to = min(to, val); }
void bye(string s, int code = 0) { cout << s << endl; exit(code); }
mt19937_64 randdev(8901016);
template<typename T> inline T rand(T l, T h) { return uniform_int_distribution<T>(l, h)(randdev); }
template<> inline double rand<double>(double l, double h) { return uniform_real_distribution<double>(l, h)(randdev); }
template<> inline float rand<float>(float l, float h) { return uniform_real_distribution<float>(l, h)(randdev); }

#if defined(_WIN32) || defined(_WIN64)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#elif defined(__GNUC__)
#else
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
namespace {
#define isvisiblechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0; T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc && cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var * sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) { input_integer<int>(var); return *this; }
        inline MaiScanner& operator>>(long long& var) { input_integer<long long>(var); return *this; }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiblechar(cc); cc = getchar_unlocked());
            for (; isvisiblechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
            return *this;
        }
        template<typename IT> void in(IT begin, IT end) { for (auto it = begin; it != end; ++it) *this >> *it; }
    };
    class MaiPrinter {
    public:
        template<typename T>
        void output_integer(T var) {
            if (var == 0) { putchar_unlocked('0'); return; }
            if (var < 0)
                putchar_unlocked('-'),
                var = -var;
            char stack[32]; int stack_p = 0;
            while (var)
                stack[stack_p++] = '0' + (var % 10),
                var /= 10;
            while (stack_p)
                putchar_unlocked(stack[--stack_p]);
        }
        inline MaiPrinter& operator<<(char c) { putchar_unlocked(c); return *this; }
        inline MaiPrinter& operator<<(int var) { output_integer<int>(var); return *this; }
        inline MaiPrinter& operator<<(long long var) { output_integer<long long>(var); return *this; }
        inline MaiPrinter& operator<<(char* str_p) { while (*str_p) putchar_unlocked(*(str_p++)); return *this; }
        inline MaiPrinter& operator<<(const string& str) {
            const char* p = str.c_str();
            const char* l = p + str.size();
            while (p < l) putchar_unlocked(*p++);
            return *this;
        }
        template<typename IT> void join(IT begin, IT end, char sep = '\n') { for (auto it = begin; it != end; ++it) *this << *it << sep; }
    };
}
MaiScanner scanner;
MaiPrinter printer;



ll N, M, K;

vector<ll> xx;

int main() {

    scanner >> N;
    xx.resize(N);
    scanner.in(ALL(xx));

    vector<ll> xs = xx;
    sort(ALL(xs));

    ll mid = N / 2 - 1;

    repeat(i, N) {
        ll t = xx[i] <= xs[mid] ? xs[mid + 1] : xs[mid];
        printer << t << '\n';
    }




    return 0;
}