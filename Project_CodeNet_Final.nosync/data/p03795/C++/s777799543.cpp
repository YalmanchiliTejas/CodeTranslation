
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define out(S) cout<<(S)<<endl;
#define REP(i,b) for(size_t i=0;i<(b);i++)
#define rREP(i,b) for(size_t i=(b)-1;i>=0;i--)
#define FOR(i,a,b) for(size_t i=(a);i<(b);i++)
#define rFOR(i,a,b) for(size_t i=(b)-1;i>=0;i--)
#define Foreach(item,collection) for(auto item:collection)
#define mod(i) ((i) % (ll)(1e9 + 7))
ll modpow(ll i, ll j) { ll tmp = 1; while (j) { if (j % 2)tmp = mod(tmp*i); i = mod(i*i); j /= 2; }return tmp; }
#define divmod(a,b) (mod(a * modpow((ll)b,(ll)(1e9 + 5))))
#define Yes out("Yes")
#define No out("No")
#define NO out("NO")
#define YES out("YES")
#define INF INT_MAX/2
#define ShowAll(collection) for(auto i:collection){out(i);}
template<typename T> pair<vector<T>,int> getAuto() {int N; cin >> N; pair<vector<T>, int> rt;rt.first.resize(N);rt.second = N;REP(i, N) cin >> rt.first[i];return rt;}
void removeAt(string& s, int index) { s.erase(index, 1); }
template<typename T> void removeAt(vector<T>& v, int index) { v.erase(v.begin() + index); }

int main(){
	int N;
	cin >> N;
	out(N * 800 - (N / 15) * 200);
}

