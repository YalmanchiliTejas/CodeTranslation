#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
#define PI 3.1415926535
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
char upper(char c){
    if('a' <= c && c <= 'z'){
        c = c - ('a' - 'A');
    }
    return c;
}
char lower(char c){
    if('A' <= c && c <= 'Z'){
        c = c + ('a' - 'A');
    }
    return c;
}
int GetDigit(int num){
    int digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }
    // 素数である
    return true;
}
ll enum_divisors(ll N) {
    ll res = 0;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res++;
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res++;
        }
    }
    // 小さい順に並び替える
    return res;
}
//input



//processing



//dpTable
//int dp[100050];
int main(){
    int X;
    cin >> X;
    cout << (X >= 30 ? "Yes" : "No") << endl;
    return 0;
}