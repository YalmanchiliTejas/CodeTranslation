#include <bits/stdc++.h>
#define LOCAL
using namespace std;
template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
out << "(" << a.first << "," << a.second << ")";
return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
out << "["; bool first = true;
for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
out << "["; bool first = true;
for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
out << "{"; bool first = true;
for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
out << "{"; bool first = true;
for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << ": " << arg1 << " |";
__f(comma + 1, args...);
}
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
//#########################################
const int mod = 1000000007;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
vector<int> f = {1},fi = {1};
int fact(int x){
    while((int)f.size() <=x)f.push_back((f.back()*f.size())%mod);
    return f[x];
}
int ifact(int x){
    return modpow(fact(x),mod-2,mod);
}
int C(int x,int y){
    if(x < y)return 0;
    return fact(x)*ifact(y)%mod*ifact(x-y)%mod;
}

signed main(){
    int h,w,k;
    cin >> h >> w >> k;
    int ret = 0;
    int iv2 = modpow(2,mod-2,mod);
    for(int i = 1;i <= h;i++)for(int j = 1;j <= w;j++){
        //ret += (i+1)*(j+1)*(i+j)/2;
        int a = j*j%mod;// - j*(j+1)*iv2 + (w-j)*(w+j+1)*iv2 -j*(w-j);
        int tmp1 = -j*(j+1)%mod*iv2%mod;
        int tmp2 = (w-j)*(w+j+1)%mod*iv2%mod;
        int tmp3 = -j*(w-j)%mod;
        a = (a+tmp1)%mod;
        a = (a+tmp2)%mod;
        a = (a+tmp3)%mod;
        a = (a*h)%mod;
        int b = i*i%mod ;//- i*(i+1)*iv2 + (h-i)*(h+i+1)*iv2 -i*(h-i);
        tmp1 = -i*(i+1)%mod*iv2%mod;
        tmp2 = (h-i)*(h+i+1)%mod*iv2%mod;
        tmp3 = -i*(h-i)%mod;
        b = (b+tmp1)%mod;
        b = (b+tmp2)%mod;
        b = (b+tmp3)%mod;
        b %= mod;
        b = (b*w)%mod;
        ret = (ret + a+b)%mod;

    }
    ret = (ret * modpow(2,mod-2,mod))%mod;
    ret = (ret*C(h*w-2,k-2))%mod;
    cout << (ret%mod + mod)%mod << endl;

    return 0;
}