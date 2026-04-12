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
int vis[10];
vector<int> g[20];
int n;
int dfs(int now){
	bool all = true;
	rep(i,n){
		if(!vis[i]){
			all = false;
			break;
		}
	}
	if(all)return 1;
	int ret = 0;
	for(auto next:g[now]){
		if(vis[next])continue;
		vis[next] = 1;
		ret += dfs(next);
		vis[next] = 0;
	}
	return ret;
}
signed main(){
	int m;cin >> n >> m;
	rep(i,m){
		int a,b;cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vis[0] = 1;
	cout << dfs(0) << endl;
	return 0;
}