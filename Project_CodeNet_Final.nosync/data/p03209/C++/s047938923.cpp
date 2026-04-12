# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
typedef pair<LL, LL> pii;
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
 
LL n, x;
LL sum[55];
LL sump[55];
 
LL calc(int level,LL num){
    if(level == 0)return 1LL;
    if(num == 1LL)return 0LL;
    else if(num <= 1LL + sum[level - 1])return calc(level - 1, num - 1LL);
    else if(num == 2LL + sum[level - 1])return sump[level - 1] + 1LL;
    else if(num <= 2LL + 2LL*sum[level - 1])return sump[level - 1] + 1LL + calc(level - 1, num - 2LL - sum[level - 1]);
    else return sump[level];
}
 
int main(){
    INIT;
    cin >> n >> x;
    sum[0] = 1LL, sump[0] = 1LL;
    for(int i = 1;i <= 50;i++)sum[i] = 3LL + sum[i - 1]*2LL;
    for(int i = 1;i <= 50;i++)sump[i] = 1LL + sump[i - 1]*2LL;
    cout << calc(n, x) << endl;
}