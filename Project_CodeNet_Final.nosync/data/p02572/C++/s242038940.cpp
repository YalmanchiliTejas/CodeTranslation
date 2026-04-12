#include <bits/stdc++.h>
namespace Suhaib_Templates {
    using namespace std;
    #define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define Alhamdulillah return 0;
    #define all(v) v.begin(),v.end()
    #define rall(v) v.rbegin(),v.rend()
    #define F_OR(i, a, b, s) for (int i = (a) ; i < (b) ; i += (s))
    #define F_OR1(e) F_OR(i, 0, e, 1)
    #define F_OR2(i, e) F_OR(i, 0, e, 1)
    #define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
    #define F_OR4(i, b, e, s) F_OR(i, b, e, s)
    #define GET5(a, b, c, d, e, ...) e
    #define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
    #define lp(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
    #define each(a,x) for (auto& a: x)
    #define pb push_back
    #define ins insert
    #define sz(v) (int) v.size()
    typedef long long ll;
    typedef long double ld;
    const long double PI = acos(-1);
    const int di[8] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
    const int dj[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};

    ll FirstTrue (ll l,ll r,function<bool(ll)>f){
        while(l<r){
        ll mid=l+(r-l)/2;
        f(mid)?r=mid:l=mid+1;} 
        return l;
    }
    ll LastTrue(ll l,ll r,function<bool(ll)>f){
        while(l<r){
        ll mid=l+(r-l+1)/2;
        f(mid)?l=mid:r=mid-1;} 
        return l;
    }
     
    ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
    ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
 
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
 
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { lp(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { lp(i,SZ) re(a[i]); }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr(x.first,' ',x.second); 
    }
    template<class T> void prContain(const T& x) {
        each(a,x) pr(a,' '); 
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { cout << '\n'; } 
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...);
    }    

    void DBG() {
        cerr << "]" << endl;
    }
    template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h);
        if(sizeof...(t))
            cerr << ", ";
        DBG(t...);
    }
    #ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
    #else
    #define debug(...) 0
    #endif
}
using namespace Suhaib_Templates;

namespace Suhaib_Modulo {
    template <typename T>
    class Modular {
     public:
      using Type = typename decay<decltype(T::value)>::type;
     
      constexpr Modular() : value() {}
      template <typename U>
      Modular(const U& x) {
        value = normalize(x);
      }
     
      template <typename U>
      static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
      }
     
      const Type& operator()() const { return value; }
      template <typename U>
      explicit operator U() const { return static_cast<U>(value); }
      constexpr static Type mod() { return T::value; }
     
      Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
      Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
      template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
      template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
      Modular& operator++() { return *this += 1; }
      Modular& operator--() { return *this -= 1; }
      Modular operator++(int) { Modular result(*this); *this += 1; return result; }
      Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
      Modular operator-() const { return Modular(-value); }
     
      template <typename U = T>
      typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    #ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
          "divl %4; \n\t"
          : "=a" (d), "=d" (m)
          : "d" (xh), "a" (xl), "r" (mod())
        );
        value = m;
    #else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    #endif
        return *this;
      }
      template <typename U = T>
      typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
      }
      template <typename U = T>
      typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
      }
     
      Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
     
      template <typename U>
      friend const Modular<U>& abs(const Modular<U>& v) { return v; }
     
      template <typename U>
      friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
     
      template <typename U>
      friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
     
      template <typename U>
      friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
     
     private:
      Type value;
    };
     
    template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
    template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
    template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
     
    template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
    template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
    template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
     
    template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
     
    template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
    template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
    template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
     
    template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
    template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
    template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
     
    template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
    template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
    template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
     
    template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
    template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
    template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
     
    template<typename T, typename U>
    Modular<T> power(const Modular<T>& a, const U& b) {
      assert(b >= 0);
      Modular<T> x = a, res = 1;
      U p = b;
      while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
      }
      return res;
    }
     
    template <typename T>
    bool IsZero(const Modular<T>& number) {
      return number() == 0;
    }
     
    template <typename T>
    string to_string(const Modular<T>& number) {
      return to_string(number());
    }
     
    template <typename T>
    std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
      return stream << number();
    }
     
    template <typename T>
    std::istream& operator>>(std::istream& stream, Modular<T>& number) {
      typename common_type<typename Modular<T>::Type, int64_t>::type x;
      stream >> x;
      number.value = Modular<T>::normalize(x);
      return stream;
    }
     
    /*
    using ModType = int;
     
    struct VarMod { static ModType value; };
    ModType VarMod::value;
    ModType& md = VarMod::value;
    using Mint = Modular<VarMod>;
    */
     
    constexpr int md = 1e9+7;// 998244353;
    using suhaib = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
}
using namespace Suhaib_Modulo;

void Suhaib_Sawalha (){

    suhaib ans = 0;
    int n;
    re(n);
    vector <suhaib> v (n);
    re(v);
    suhaib sum = accumulate(all(v),(suhaib)0);
    lp(n){
        sum -= v[i];
        ans += v[i] * sum;
    }
    pr(ans);

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
// int _;cin>>_;for(int i=1;i<=_;++i,cout<<'\n')
        // cout<<"Case #"<<i<<":\n", 
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}