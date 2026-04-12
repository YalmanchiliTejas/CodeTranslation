
/*
	*	Created By: 'Present_Sir'
	*	Created On: Saturday 29 August 2020 05:40:55 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define lgt(s) ((int)s.length())
#define int long long
using namespace std;

const int mod = (int)1e9+7;

const int Mod = 1e9+7;

template <int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % mod + mod) >= mod) x -= mod;
    }
    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        x = (unsigned long long)x * rhs.inv().x % mod;
        return *this;
    }
 
    ModInt operator-() const { return -x < 0 ? mod - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return pow(*this, mod - 2); }
 
    friend ostream& operator<<(ostream& s, ModInt<mod> a) {
        s << a.x;
        return s;
    }
    friend istream& operator>>(istream& s, ModInt<mod>& a) {
        s >> a.x;
        return s;
    }
};
 
using mint = ModInt<Mod>;
int expo(int a, int k){
    if(k == 0){
        return 1;
    }
    int ans = expo( (a*a)%mod, k/2);
    if(k%2 == 1){
        return (ans*a)%mod;
    }
    return ans%mod;
}

class Solver{
    public:
        void test(){
            //int t; cin>>t; for(int i=1; i<=t; ++i)
            {
                //cout<<"Case #"<<i<<": ";
                this->solve();
            }
        }
        void solve(){
            int n;
            cin>>n;
            vector < int > v(n);
            mint sum = 0;
            for(int i=0; i<n; ++i){
                cin>>v[i];
                sum += v[i];
            }
            
            mint ans = 0;
            for(int i=0; i<n; ++i){
                sum -= v[i];
                ans += (sum)*v[i];
            }
            cout<<ans<<endl;
        
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}

