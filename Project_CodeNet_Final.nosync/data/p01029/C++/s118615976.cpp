#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
	for (auto& e : t) fill_v(e, v);
}


// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T & a, const T & b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}


#define ARRAY_MAX 100005
const int INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


/******************************************************************************************/

vector<int> Edge[100005];
int check[100005][30];

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int V,E;
	cin >> V >> E;
	vector<char> A(V);
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < V; i++)
	{
		cin >> A[i];
		if(A[i] != '?'){
			check[i][A[i]-'a'] = 1;
		}
	}
	
	for (int i = 0; i < E; i++)
	{
		int s,t;
		cin >> s >> t;
		Edge[s].push_back(t);
		Edge[t].push_back(s);
	}
	
	for (int i = 0; i < V; i++)
	{
		//今見ている頂点
		if(A[i] != '?')continue;
		for(auto letter:alpha){
			//埋め込むアルファベットの候補
			bool flag = true;
			if(check[i][letter-'a'])continue;
			for(auto nearId:Edge[i]){
				//周囲に既に使われていないかの確認
				//nearIdはインデックス番号
				if(check[nearId][letter-'a']){
					flag = false;
					break;
				}
			}
			
			if(flag){
				//cout << "i= " << i << " letter= " << letter << endl;
				//letterは使用可能
				check[i][letter-'a'] = 1;
				A[i] = letter;	
				/*for(auto nearId:Edge[i]){
					check[nearId][letter-'a'] = 1;
				}*/
				break;
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		cout << A[i];
	}
	
	cout << endl;
	return 0;
}


