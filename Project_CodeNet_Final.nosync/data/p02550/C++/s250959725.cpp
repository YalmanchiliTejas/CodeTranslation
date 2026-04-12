#include <bits/stdc++.h>
using namespace std;
typedef long long lol;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(lol i=0;i<lol(n);i++)
#define REPD(i,n) for(lol i=n-1;i>=0;i--)
#define FOR(i,a,b) for(lol i=a;i<=lol(b);i++)
#define FORD(i,a,b) for(lol i=a;i>=lol(b);i--)
#define VL vector<lol>
//xにはvectorなどのコンテナ
#define ALL(x) x.begin(),x.end() //sortなどの引数を省略したい
#define SIZE(x) lol(x.size()) //sizeをsize_tからllに直しておく
//定数
#define PI 3.1415926535897932385 //pi
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//最大値最小値
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
//繰り返し二乗法
int modPow(long long a, long long n, long long p) {
    if (n == 0) return 1; // 0乗にも対応する場合
    if (n == 1) return a % p;
    if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}
int modDev(lol a, lol b, lol c)
{
    if(a < b || a < 0) return 1;
    return (a*(modPow(b, c-2, c)))%MOD;
}
int finds(lol a[], lol b, lol c)
{
    REP(i, c)
    {
        if(a[i] == b) return i;
    }
    return -1;
}

int main()
{
    lol result{0};
    lol a[100005] = {}, count = 0;
    lol n, x, m; cin >> n >> x >> m;
    lol prex = x;
    lol save2 = 0, save3 = 0;
    //bool TF = false;
    a[0] = x;
    FOR(i, 2, n)
    {
        lol save = (prex*prex)%m;
        if(finds(a, save, count) != -1)
        {
            save2 = finds(a, save, count);
            break;
        }
        else
        {
            count++;
            a[count] = save;
            prex = save;
        }
        
    }
    FOR(i, save2, count)
    {
        save3 += a[i];
    }
    lol nm = count - save2 + 1;
    REP(i, save2) result += a[i];
    lol nm2 = (n-save2)/nm;
    lol nmr = (n-save2)%nm;
    result += save3*nm2;
    REP(i, nmr)
    {
        result += a[save2+i];
    }
    

    cout << result << endl;
    return 0;
}