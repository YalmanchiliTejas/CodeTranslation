#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? 1e9:1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T a){for(auto itr :a){if(itr != *a.begin())cout << " "; cout << itr;} }
using ll  = long long;
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
int calm(string s){
        stack<int>num;
    int res = 0;
    rep(i,s.size()){
        char c = s[i];
        if(c == '*'){
            int t = (s[++i]-'0') * num.top();
            num.pop();
            num.push(t);
        } else if(c == '+'){
        } else num.push(c-'0');
    }
    while(not num.empty()){res += num.top(); num.pop();}
    return res;
}
int call(string s){
    int res = 0;
    rep(i,s.size()){
        char c  = s[i];
    if('0' <= c and c <= '9')res += c -'0';
    else if(c == '*'){
        res *= (s[++i] - '0');
    } else
        res += (s[++i] - '0');
    }
    return res;
}
#define int ll
signed main(){
    string s; cin >> s;
    int val; cin >> val;
    int m = calm(s);
    int l = call(s);
    if(m == l and l == val) cout << "U" << endl;
    else if(val == m) cout << "M" << endl;
    else if(val == l)cout << "L" << endl;
    else cout << "I" << endl;
}




