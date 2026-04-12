#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/range/adaptor/reversed.hpp>

using namespace std;
typedef long long int ll;

#define PI (acos(-1))
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define dumparr(x) cerr << #x ; for(auto elem: x){cerr << " " << elem;} cerr << endl;
#define dumppairs(x) cerr << #x ; for(auto elem: x){cerr << "(" << elem.first << " " << elem.second << ") ";} cerr << endl;
#define dumpline cerr << "**********************" << endl;
#define dumpwline(x) cerr << "******** " << #x << "=" << (x) << " ********" << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int d = 998244353;

vector <long> gyakus(5e6+10, 0);
int gyaku(long num){
    int e = d - 2;
    long ret = 1;
    long keta = num;
    while (e > 0){
        if (e%2 == 1){
            ret = keta*ret % d;
        }
        e /= 2;
        keta = keta*keta % d;
    }
    return ret;
}

int main(void){
    int n; cin >> n;

    REP(i, n/2 + 10){
        gyakus[i+1] = gyaku(i+1);
    }
    long ans = 1;
    long keta = 3;
    int m = n;
    while (m > 0){
        if (m%2 == 1){
            ans = keta*ans % d;
        }
        m /= 2;
        keta = keta*keta % d;
    }
    ll nozoku = 0;
    ll comb = 1;
    ll two = 1;
    REP(i, n/2){
        nozoku += comb * two;
        nozoku %= d;

        two *= 2;
        two %= d;

        comb *= n-i;
        comb %= d;
        comb *= gyakus[i+1];
        comb %= d;
    }
    ans = ans + d * 2 - nozoku * 2;
    cout << ans % d << endl;
    return 0;
}