#if __has_include("noamoa_atcoder_lib.h")
#include "noamoa_atcoder_lib.h"
#else
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
namespace atcoder {
	using namespace std;
	using ll = long long;
	using llv = vector<ll>;
	using intv = vector<int>;
	using charv = vector<char>;
	using boolv = vector<bool>;
	using floatv = vector<float>;
	using doublev = vector<double>;
	using stringv = vector<string>;

	constexpr ll MOD7 = 1000000007;
	constexpr ll MOD9 = 1000000009;

	void reverse(string& s){
		reverse(all(s));
	}

	template<typename T>
	void init(vector<T>& v, T initVal = T()){
		for(auto& e : v){
			e = initVal;
		}
	}

	template<typename T>
	void sort(vector<T>& v){
		sort(all(v));
	}
	template<typename T>
	void sortInv(vector<T>& v){
		sort(all(v), greater<T>());
	}

	template<typename T>
	void reverse(vector<T>& v){
		reverse(all(v));
	}

	template<typename T>
	T sum(const vector<T>& v){
		T ret = 0;
		for(const auto& e : v) ret += e;
		return ret;
	}

	template<typename T>
	inline vector<T>& operator+=(vector<T>& v, const T& e){
		v.push_back(e);
		return v;
	}

	template<typename T1, typename T2>
	inline vector<T1>& operator+=(vector<T1>& v1, const vector<T2>& v2){
		for(const auto& e : v2) v1.push_back(e);
		return v1;
	}

	template<typename T>
	void in(vector<T>& v){
		for(auto& e : v) cin >> e;
	}

	template<typename T1, typename T2>
	void in(vector<T1>& v1, vector<T2>& v2){
		for(int i=0;i<v1.size();i++)
			cin >> v1[i] >> v2[i];
	}
	template<typename T1, typename T2, typename T3>
	void in(vector<T1>& v1, vector<T2>& v2, vector<T3>& v3){
		for(int i=0;i<v1.size();i++)
			cin >> v1[i] >> v2[i] >> v3[i];
	}
	template<typename T1, typename T2, typename T3, typename T4>
	void in(vector<T1>& v1, vector<T2>& v2, vector<T3>& v3, vector<T4>& v4){
		for(int i=0;i<v1.size();i++)
			cin >> v1[i] >> v2[i] >> v3[i] >> v4[i];
	}

	template<typename T>
	istream& operator>>(istream &stream, vector<T>& v){
		for(auto& e : v) stream >> e;
		return stream;
	}

	template<typename T>
	void out(const vector<T>& v){
		for(const auto& e : v) cout << e << ' ';
		cout << endl;
	}

	template<typename T>
	void outln(const vector<T>& v){
		for(const auto& e : v) cout << e << endl;
	}

	template<typename T>
	inline set<T>& operator+=(set<T>& v, const T& e){
		v.insert(e);
		return v;
	}

	template<typename T1, typename T2>
	inline set<T1>& operator+=(set<T1>& v1, const set<T2>& v2){
		for(const auto& e : v2) v1.insert(e);
		return v1;
	}

	constexpr ll modPow(ll x, ll n, ll m){ // O(logn)
		if(n == 0) return 1;
		else if(n % 2 == 0) return modPow((x * x) % m, n / 2, m);
		else return x * modPow(x, n - 1, m) % m;
	}
}
using namespace atcoder;
#endif

int main(){
	cout << fixed << setprecision(15);
	
	
	string s;cin>>s;
	cout << (s=="AAA"||s=="BBB"?"No":"Yes");
}