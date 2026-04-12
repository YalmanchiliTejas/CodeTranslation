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
signed main(){
    int n,x,m;cin >> n >> x >> m;
    vector<int> a = {x};
    vector<int> vis(m+1);
    int val = 0;
    while(1){
        int tmp = (a.back()*a.back())%m;
        // trace(tmp);
        if(vis[tmp]){
            val = tmp;
            break;
        }
        a.push_back(tmp);
        vis[tmp] = 1;
    }
    int T= 0;
    for(;a[T] != val;T++);
    // trace(T,(int)a.size()-T);    
    T = (int)a.size() -T;
    // trace(a);
    int ret = 0;
    int i;
    for(i = 0;i < (int)a.size();i++){
        int x = a[i];
        if(x == val)break;
        // trace(x);
        int tmp = x;
        ret += tmp;
    }
    n-= i;
    // trace(n);
    int cnt = 0;
    for(;i < (int)a.size();i++){
        int x = a[i];
        // trace(x);
        int tmp = (n/T)*x;
        ret += tmp;
        cnt+= n/T;
    }
    n -= cnt;
    // trace(n);
    // trace(a);
    // trace(a.size());
    for(i = 0;i < a.size() && a[i] != val;i++);
    for(int j = i;j < min(i+n,(int)a.size());j++){
        ret += a[j];
    }
    cout << ret << endl;
    return 0;
}