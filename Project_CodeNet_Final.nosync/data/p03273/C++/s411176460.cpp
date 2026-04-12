#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(ll i##_len=(n) ,i=i##_len-1;i>=0;--i)
#define repi(i,a,b) for(ll i=ll(a);i<=ll(b);++i)
#define ALL(f,x,...) ([&](decltype((x)) xxxx) { return (f)(begin(xxxx), end(xxxx), ## __VA_ARGS__); })(x)
#define lim 1000000007ll
#define Yes(flag) cout<<((flag)? "Yes":"No");
#define YES(flag) cout<<((flag)? "YES":"NO");
#define which(flag,msg1,msg2) cout<<((flag)? msg1:msg2);

#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = std::pair<ll,ll>;
using namespace std;
template<class T>T 
chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>T 
chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template <class T> T 
gcd(T a, T b){if (a < b) {a ^= b;b ^= a;a ^= b;} return b ? gcd(b, a % b) : a;}
template <class T> T 
lcm(T a, T b){return a * b / gcd(a, b);}
vector<char> 
string_to_vector_char(const string& input){vector<char> out(input.length());rep(i,input.length()){out[i]=input[i];}return out;}
map<char,int> 
count_same_elements(const vector<char>& v){map<char,int>cmap; for_each(v.begin(),v.end(),[&cmap](int x){cmap[x]++;}); return cmap; }
template<class A,class B> vector<B> 
mapf(const vector<A>& v,const function<B(A)>& func){vector<B> v_(v.size());rep(i,v.size()){ v_[i]=func(v[i]); }return v_;}
template<class A,class B> vector<B> 
adjacent_map(const vector<A>& v,const function<B(A,A)>& func){vector<B> v_(v.size()-1);rep(i,v.size()-1){ v_[i]=func(v[i+1],v[i]); }return v_;}
template<class A> bool
all_of(const vector<A>& v){bool flag=true;rep(i,v.size()){ if(v[i]<1){flag=false;}; }return flag;}
template<class A> bool
any_of(const vector<A>& v){bool flag=false;rep(i,v.size()){ if(v[i]>0){flag=true; break;}; }return flag;}
template<class A> bool
none_of(const vector<A>& v){bool flag=true;rep(i,v.size()){ if(v[i]>0){flag=false;}; }return flag;}
template<class T>
void scan_vector(long long size,vector<T>& vector){
    vector.resize(size);
    for(long long i=0;i<size;++i){
        cin>>vector[i];
    }
}
// 約数列挙
template <class T>
vector< T > divisor(T n) {
    vector< T > ret;
    for(T i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        ret.push_back(i);
        if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

ll h,w;
vector<string> s;
void input(){
    cin>>h>>w;
    scan_vector(h,s);
}
void src(){
    vector<vector<int>> f(h); vector<int> kn(h,1);
    rep(i,h) f[i].resize(w,1);
    rep(i,h){
        if(all_of(s[i].begin(),s[i].end(),[](auto x){return x=='.';})){
            rep(j,w) f[i][j]=0;
            kn[i]=0;
        };
    }
    rep(i,w){
        bool fl=true;
        rep(j,h) if(s[j][i]=='#'){fl=false;break;}
        if(fl){
            rep(j,h) f[j][i]=false;
        }
    }
    rep(i,h){
        if(kn[i]){
        rep(j,w){
            if(f[i][j])
                cout<<s[i][j];
        }
        cout<<"\n";

        }
    }


}   

int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
 //   ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
    return 0;
}