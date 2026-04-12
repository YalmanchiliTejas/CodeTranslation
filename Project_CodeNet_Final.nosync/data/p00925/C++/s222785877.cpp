#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <utility>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#define each(e,c) for(auto&e:c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#ifdef DEBUG
#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<" ["<<__LINE__<<"]"<<endl)
struct DUMP:ostringstream{template<class T>DUMP &operator,(const T&t){if(this->tellp())*this<<", ";*this<<t;return *this;}};
#else
#define dump(...)
#endif
template<class T> ostream& operator<<(ostream& os, vector<T> const& v){
    rep(i,v.size()) os << v[i] << (i+1==v.size()?"":" ");
    return os;
}

#define int ll

int parseL(string s){
    int res = s[0]-'0';
    rep(i,s.size()){
        if(s[i]=='*') res*=s[i+1]-'0';
        else if(s[i]=='+')res+=s[i+1]-'0';
    }
    return res;
}

int parseM(string s){
    vi v={s[0]-'0'};
    rep(i,s.size()){
        if(s[i]=='*') v.back()*=s[i+1]-'0';
        else if(s[i]=='+') v.pb(s[i+1]-'0');
    }
    int x = 0;
    rep(i,v.size()) x+=v[i];
    return x;
}

signed main(){
    string s;
    while(cin >> s){
    ll x; cin >> x;
    int a = parseM(s);
    int b = parseL(s);
    char ans;
    if(x==a && x==b) ans = 'U';
    else if(x==a) ans = 'M';
    else if(x==b) ans = 'L';
    else ans = 'I';
    cout << ans << endl;
}
}