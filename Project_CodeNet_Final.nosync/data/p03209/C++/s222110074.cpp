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
int all[100],pate[100];
int dfs(int level,int remain){
    if(remain == 0)return 0;
    int ret =0;
    //ban
    if(remain > 0){
        remain--;
    }

    //l-1
    if(remain >= all[level-1]){
        remain -= all[level-1];
        ret += pate[level-1];

    }
    else{
        ret += dfs(level-1,remain);
        remain = 0;
    }

    //pate
    if(remain > 0){
        ret++;
        remain--;
    }

    //l-1
    if(remain >= all[level-1]){
        remain -= all[level-1];
        ret += pate[level-1];

    }
    else{
        ret += dfs(level-1,remain);
        remain = 0;
    }


    //ban
    if(remain > 0){

        remain--;
    }
    return ret;
}
signed main(){
    int n,x;cin >> n >> x;
    pate[0] = 1;
    all[0] = 1;
    rep(i,n+1){
        if(i)all[i] = all[i-1]*2 + 3;
        if(i)pate[i] = pate[i-1]*2 + 1;
        //trace(i,all[i],pate[i]);
    }
    cout << dfs(n,x) << endl;
    return 0;
}