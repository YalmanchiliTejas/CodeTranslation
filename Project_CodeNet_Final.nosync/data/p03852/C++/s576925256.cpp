#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(ll i##_len=(n) ,i=i##_len-1;i>=0;--i)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define fe(vec,lambda) std::for_each(vec.begin(), vec.end(), lambda );
#define printd(val) std::cout<< #val" = " <<val<<"\n";
#define printv(val) std::for_each(val.begin(),val.end(),[](auto x){cout<<x<<"\n";});
#define lim 1000000007ll
#include<bits/stdc++.h>
using ll = long long;
using pii = std::pair<ll,ll>;
using namespace std;
template<class T>T chmin(T& a,T b){if(a>b){a^=b;b^=a;a^=b;return 1;}return 0;}
template<class T>T chmax(T& b,T a){if(a>b){a^=b;b^=a;a^=b;return 1;}return 0;}
template <class T> T gcd(T a, T b){if (a < b) {a ^= b;b ^= a;a ^= b;} return b ? gcd(b, a % b) : a;}
template <class T> T lcm(T a, T b){return a * b / gcd(a, b);}
inline bool operator<(const pii &lhs,const pii &rhs){return(lhs.second<rhs.second);}
template<class T> vector<pair<T,T>> duplicator(const vector<T>& input){vector<pair<T,T>> out(input.size()-1);rep(i,input.size()-1){out[i].first =input[i  ];out[i].second=input[i+1];}return(out);}
vector<char> String_to_vector_char(const string& input){vector<char> out(input.size());rep(i,input.size()){out[i]=input[i];}return out;}


ll a,b,c;
vector<ll>v;
map<ll,ll>m;
string s,s2;
void input(){
    cin>>s;
    s2="aiueo";
}
void src(){
    cout<<(s2.find(s[0])!=string::npos? "vowel":"consonant");
}

int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
    //ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
    return 0;
}