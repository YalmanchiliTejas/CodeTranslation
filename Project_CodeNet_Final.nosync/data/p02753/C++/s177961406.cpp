#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(ll i=0,i##_len=(n);i<i##_len;i++)
#define rep2(i,a,b) for(ll i=(a),i##_len=(b);i<=i##_len;i++)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define pb push_back
using namespace std;
using ll = long long;

template<class T> bool chmax(T&a,const T&b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T&a,const T&b){if(a>b){a=b;return true;}return false;}
template<class T> void show(vector<T>v){rep(i,v.size()-1){cout<<v.at(i)<<" ";}cout<<v.at(v.size()-1)<<endl;}
template<class T> T abs(T x){return max(x,-x);}
template<class T> T gcd_vec(vector<T>v){T r=v.at(0);for(T i=1;i<v.size();i++)r=gcd(r,v.at(i));return r;}
template<class T> T lcm(T m,T n) {return m*n/gcd(m,n);}
template<class T> T lcm_vec(vector<T>v){T r=v.at(0);for(T i=1;i<v.size();i++)r=lcm<T>(r,v.at(i));return r;}
template<class T> T factorial(T n){if(n==0)return 1;T r=1;for(T i=2;i<=n;i++)r*=i;return r;}
template<class T> T nCr(T n,T k){return factorial<T>(n)/(factorial<T>(k)*factorial<T>(n-k));}
vector<string> split(const string&s,char d){vector<string>r;stringstream ss(s);string k;while(getline(ss,k,d))if(!k.empty())r.pb(k);return r;}

// Template ends here

int main() {
    string s;
    cin >> s;
    Yes(!(s.at(0) == s.at(1) && s.at(1) == s.at(2)));
    return 0;
}