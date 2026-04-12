#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(ll i##_len=(n) ,i=i##_len-1;i>=0;--i)
#define repi(i,a,b) for(ll i=ll(a);i<=ll(b);++i)
#define ALL(f,x,...) ([&](decltype((x)) xxxx) { return (f)(begin(xxxx), end(xxxx), ## __VA_ARGS__); })(x)
#define lim 1000000007ll
#define Yes(flag) cout<<((flag)? "Yes":"No");
#define YES(flag) cout<<((flag)? "YES":"NO");
#define MSG(msg1,msg2,flag) cout<<((flag)? msg1:msg2);

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
template <class T> map<T,int> 
count_same_elements(const vector<T>& v){map<T,int>cmap; for_each(v.begin(),v.end(),[&cmap](auto x){cmap[x]++;}); return cmap; }
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
int n;
vector<int> h;
void input(){
    cin>>n;
    scan_vector(n,h);
}
void src(){
    int ans=0;
    rep(i,n){
        bool f=true;
        rep(j,i){
            if(h[j]>h[i]) f=false;
        }
        ans+=f;
    }
    cout<<ans;
}   

int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
 //   ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
    return 0;
}