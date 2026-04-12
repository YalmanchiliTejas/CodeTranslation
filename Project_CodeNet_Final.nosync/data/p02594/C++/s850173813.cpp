#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <ctime>
#define ll long long
#define debug cout << "debug" << endl
#define STOPSYNC ios::sync_with_stdio(false);cin.tie(nullptr)
#define MULTIKASE int Kase=0;cin>>Kase;for(int kase=1;kase<=Kase;kase++)
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template <typename T>
inline void w(T x) {
    if (x > 9) w(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x, char c) {
    w(x);
    putchar(c);
}
template <typename T>
inline void read(T &x) {
    x = 0;
    T f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
    for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    x *= f;
}
template <typename T>
T MAX(T a, T b) {
    return a > b ? a : b;
}
template <typename T>
T MIN(T a, T b) {
    return a > b ? b : a;
}
template <typename T>
T GCD(T a, T b){
    return b == 0 ? a : GCD(b, a % b);
}
template <typename T>
T LCM(T a, T b){
    return a / GCD(a, b) * b;
}
void solve(){
    
}
int main(){
    int n;
    cin >> n;
    printf("%s\n", n >= 30 ? "Yes" :"No");
    return 0;
}