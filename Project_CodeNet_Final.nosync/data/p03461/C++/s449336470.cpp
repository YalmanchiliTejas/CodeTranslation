#include <cstdio>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <iterator>
#include <array>


struct Range
{   
    struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
    Range(int ee):b(0),e(ee){}
    Range(int bb, int ee):b(bb), e(ee){}
    It begin(){return {b, (b < e? 1: -1)};}
    It end(){return {e, 0};}
    int b, e;
};

template<typename T> inline T& UMAX(T& x, T y){if(x < y)x = y; return x;}
template<typename T> inline T& UMIN(T& x, T y){if(y < x)x = y; return x;}
template<typename T, typename... Args> struct ArithmiticPromotion { typedef decltype(T() + typename ArithmiticPromotion<Args...>::type()) type; };
template<typename T, typename U> struct ArithmiticPromotion<T, U> { typedef decltype(T() + U()) type; };
template<typename T> struct ArithmiticPromotion<T, T> { typedef T type; };
template<typename T> struct ArithmiticPromotion<T> { typedef T type; };
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MAX(T a, U b) { return a < b? b: a; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MAX(T a, Args... args) { return MAX(a, MAX(args...)); }
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MIN(T a, U b) { return a < b? a: b; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MIN(T a, Args... args) { return MIN(a, MIN(args...)); }



template<typename T> struct ScanfSpecifier{};
#define DEF(T,V) template<> struct ScanfSpecifier<T>{static constexpr const char* value = V;};
DEF(char*,"%s")DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(unsigned int, "%u")DEF(long double, "%Lf")
#ifdef _MSC_VER
DEF(long long int,"%I64d")
#else
DEF(long long int,"%lld")
#endif
#undef DEF
template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
int RD(char* arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename T> T RD(){T ret; RD(ret); return ret;}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename T> void WT(T arg) {std::printf(ScanfSpecifier<T>::value, arg); }
template<typename T, typename U> void WT(std::pair<T, U> arg) {std::printf("("); WT(arg.first); std::printf(", "); WT(arg.second); std::printf(")");}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), WT(args), 0)...}; }

template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void WTVL(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void WTVL(const C& c) {WTVL(std::begin(c), std::end(c));}

#define _M_VARGS_NUM_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define _M_VARGS_NUM(...) _M_VARGS_NUM_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define _W1(_1) (#_1[0] == '"' || #_1[0] == '\''? WT("", _1, ""): WT('[', #_1, '=', _1, ']'))
#define _W2(_1, _2) (_W1(_1), _W1(_2))
#define _W3(_1, _2, _3) (_W1(_1), _W2(_2, _3))
#define _W4(_1, _2, _3, _4) (_W1(_1), _W3(_2, _3, _4))
#define _W5(_1, _2, _3, _4, _5) (_W1(_1), _W4(_2, _3, _4, _5))
#define _W6(_1, _2, _3, _4, _5, _6) (_W1(_1), _W5(_2, _3, _4, _5, _6))
#define _W7(_1, _2, _3, _4, _5, _6, _7) (_W1(_1), _W6(_2, _3, _4, _5, _6, _7))
#define _W8(_1, _2, _3, _4, _5, _6, _7, _8) (_W1(_1), _W7(_2, _3, _4, _5, _6, _7, _8))
#define _WW_IMPL2(num, ...) _W ## num(__VA_ARGS__)
#define _WW_IMPL(num, ...) _WW_IMPL2(num, __VA_ARGS__)
#define WW(...) (std::printf("(%03d) ", __LINE__), _WW_IMPL(_M_VARGS_NUM(__VA_ARGS__), __VA_ARGS__), WTL(""))




//alias
using RG = Range;
//RD[L],RDV[L],WT[L],WTV[L] for i/o
//template
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long int ll;

int d[16][16];

int main()
{
    int A, B;
    RD(A, B);

    for(int i: RG(1, A + 1))
        RDV(d[i] + 1, d[i] + B + 1);

    vector<pair<int, int>> adj[300];
    set<int> adj2[300];

    for(int i = 1; i <= 100; i++)
        adj[i].push_back({i + 1, -1});
    for(int i = 102; i <= 201; i++)
        adj[i].push_back({i + 1, -2});

    bool solved = true;
    for(int i: RG(1, A + 1))
        for(int j: RG(1, B + 1))
        {
            int xx = -1, yy = -1;
            for(int x = 0; x <= 100 && xx == -1; x++)
                for(int y = 0; y <= 100 && xx == -1; y++)
                {
                    if(x * i + y * j > d[i][j])
                        continue;

                    bool check = true;
                    for(int ii = 1; ii <= A && check; ii++)
                        for(int jj: RG(1, B + 1))
                            if(!(i == ii && j == jj))
                            {
                                int dx = ii - i;
                                int dy = jj - j;
                                int dd = d[ii][jj] - d[i][j];

                                if(x * dx + y * dy < dd)
                                {
                                    check = false;
                                    break;
                                }


                            }
                    if(check)
                    {
                        xx = x;
                        yy = y;
                    }
                }
            if(xx == -1)
                solved = false;
            else if(adj2[xx + 1].insert(202 - yy).second)
                adj[xx + 1].push_back({202 - yy, d[i][j] - xx * i - yy * j});
        }

    if(!solved)
        WTL("Impossible");
    else
    {
        WTL("Possible");
        int N = 202;
        int M = 0;
        for(int i: RG(1, N + 1))
            M += adj[i].size();
        WTL(N, M);
        for(int i: RG(1, N + 1))
            for(auto p: adj[i])
            {
                WT(i, p.first, "");
                if(p.second == -1)
                    WTL("X");
                else if(p.second == -2)
                    WTL("Y");
                else
                    WTL(p.second);
            }
        WTL(1, 202);



    }

}




