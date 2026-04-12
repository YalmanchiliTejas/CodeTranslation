//#define NDEBUG

#pragma GCC optimize ("O3") // 最適化レベルの変更 O0〜O3 などを指定
#pragma GCC optimize("-O3,inline,omit-frame-pointer,unroll-loops")
#pragma warning(1:4456) // 多重forループ内での変数の２重定義を警告にする

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <bitset>

#include <memory>
#include <cassert>

#include <functional>
#include <chrono>

using namespace std;

namespace ValLib {

	typedef unsigned int uint;
	typedef long long ll;
	typedef unsigned long long ull;

	constexpr ull V_MOD = 1000000007ull;
	constexpr int V_INT_MAX = 2147483647;
	constexpr ll V_LL_MAX = 9223372036854775807ll;
	constexpr ull V_ULL_MAX = 18446744073709551615ull;

	template<typename Key, typename Value>
	using umap = std::unordered_map<Key, Value>;
	template<typename T>
	using uset = std::unordered_set<T>;
	template <typename T>
	using sptr = typename std::shared_ptr<T>;
	class vnode;
	class vegde;
	class vgraph;

	template<typename T>void fill(vector<T>&vec,const T&value){std::fill(vec.begin(),vec.end(),value);}
	template<typename T>void fill(vector<vector<T>>&vec,const T&value){for(vector<T>&t:vec)std::fill(t.begin(),t.end(),value);}
	template<typename T>void resize(vector<T>&vec,int size1){vec.resize(size1);}
	template<typename T>void resize(vector<T>&vec,int size1,const T& value){vec.resize(size1,value);}
	template<typename T>void resize(vector<vector<T>>&vec,int size1,int size2){vec.resize(size1);for(vector<T>&t:vec)t.resize(size2);}
	template<typename T>void resize(vector<vector<T>>&vec,int size1,int size2,const T& value){vec.resize(size1);for(vector<T>&t:vec)t.resize(size2,value);}
	template<typename T>void assign(vector<T>&vec,int size1,const T& value){vec.assign(size1,value);}
	template<typename T>void assign(vector<vector<T>>&vec,int size1,int size2,const T& value){vec.resize(size1);for(vector<T>&t:vec)t.assign(size2,value);}
	template<typename T>const typename vector<T>::const_iterator max_element(const vector<T>&vec){assert(!vec.empty());return std::max_element(vec.begin(),vec.end());}
	template<typename T,typename _Pr>const typename vector<T>::const_iterator max_element(const vector<T>&vec,_Pr lessThan){assert(!vec.empty());return std::max_element(vec.begin(),vec.end(),lessThan);}
	template<typename T>typename vector<T>::iterator min_element(vector<T>&vec){assert(!vec.empty());return std::min_element(vec.begin(),vec.end());}
	template<typename T>const typename vector<T>::const_iterator min_element(const vector<T>&vec){assert(!vec.empty());return std::min_element(vec.begin(),vec.end());}
	template<typename T,typename _Pr>const typename vector<T>::const_iterator min_element(const vector<T>&vec,_Pr lessThan){assert(!vec.empty());return std::min_element(vec.begin(),vec.end(),lessThan);}
	int accumulate(const vector<int>&vec){return std::accumulate(vec.begin(),vec.end(),0);}
	template<typename _Pr>int accumulate(const vector<int>&vec,_Pr func){return std::accumulate(vec.begin(),vec.end(),0,func);}
	double accumulate(const vector<double>&vec){return std::accumulate(vec.begin(),vec.end(),0.0);}
	template<typename _Pr>double accumulate(const vector<double>&vec,_Pr func){return std::accumulate(vec.begin(),vec.end(),0.0,func);}
	float accumulate(const vector<float>&vec){return std::accumulate(vec.begin(),vec.end(),0.f);}
	template<typename _Pr>float accumulate(const vector<float>&vec,_Pr func){return std::accumulate(vec.begin(),vec.end(),0.f,func);}
	template<typename T,typename _Pr>bool all_of(const vector<T>&vec,_Pr pred){return std::all_of(vec.begin(),vec.end(),pred);	}
	template<typename T,typename _Pr>bool any_of(const vector<T>&vec,_Pr pred){return std::any_of(vec.begin(),vec.end(),pred);}
	template<typename T,typename _Pr>bool none_of(const vector<T>&vec,_Pr pred){return std::none_of(vec.begin(),vec.end(),pred);}
	template<typename T>const typename vector<T>::const_iterator find(const vector<T>&vec,const T& val){return std::find(vec.begin(),vec.end(),val);}
	template<typename T,typename _Pr>const typename vector<T>::const_iterator find_if(const vector<T>&vec,_Pr pred){return std::find_if(vec.begin(),vec.end(),pred);}
	template<typename T>bool contains(const vector<T>&vec,const T& val){return std::find(vec.begin(),vec.end(),val) != vec.end();}
	template<typename T,typename _Pr>bool contains_if(const vector<T>&vec,_Pr pred){return std::find_if(vec.begin(),vec.end(),pred)!=vec.end();}
	template<typename T,typename _Pr>typename iterator_traits<const typename vector<T>::const_iterator>::difference_type count_if(const vector<T>&vec,_Pr pred){return std::count_if(vec.begin(),vec.end(),pred);}
	template<typename T>void sort(vector<T>&vec){std::sort(vec.begin(),vec.end());}
	template<typename T,typename _Pr>void sort(vector<T>&vec,_Pr pred){std::sort(vec.begin(),vec.end(),pred);}
	template<typename T>void stable_sort(vector<T>&vec){std::stable_sort(vec.begin(),vec.end());}
	template<typename T,typename _Pr>void stable_sort(vector<T>&vec,_Pr pred){std::stable_sort(vec.begin(),vec.end(),pred);}

	template<typename T,size_t N>void fill(array<T,N>&ary,const T& value){std::fill(ary.begin(),ary.end(),value);}
	template<typename T,size_t N,size_t M>void fill(array<array<T,M>,N>&ary,const T& value){ for(array<T,M>& t : ary) std::fill(t.begin(),t.end(),value);}
	template<typename T,size_t N,typename _Pr>const typename array<T,N>::const_iterator max_element(const array<T,N>&ary){assert(!ary.empty());return std::max_element(ary.begin(),ary.end());}
	template<typename T,size_t N,typename _Pr>const typename vector<T>::const_iterator max_element(const array<T,N>&ary){assert(!ary.empty());return std::max_element(ary.begin(),ary.end());}
	template<typename T,size_t N,typename _Pr>const typename array<T,N>::const_iterator max_element(const array<T,N>&ary,_Pr lessThan){assert(!ary.empty());return std::max_element(ary.begin(),ary.end(),lessThan);}
	template<typename T,size_t N,typename _Pr>const typename array<T,N>::const_iterator min_element(const array<T,N>&ary){assert(!ary.empty());return std::min_element(ary.begin(),ary.end());}
	template<typename T,size_t N,typename _Pr>const typename array<T,N>::const_iterator min_element(const array<T,N>&ary,_Pr lessThan){assert(!ary.empty());return std::min_element(ary.begin(),ary.end(),lessThan);}
	template<size_t N>int accumulate(const array<int,N>&ary){return std::accumulate(ary.begin(),ary.end(),0);}
	template<size_t N,typename _Pr>int accumulate(const array<int,N>&ary,_Pr func){return std::accumulate(ary.begin(),ary.end(),0,func);}
	template<size_t N>double accumulate(const array<double,N>&ary){return std::accumulate(ary.begin(),ary.end(),0.0);}
	template<size_t N,typename _Pr>double accumulate(const array<double,N>&ary,_Pr func){return std::accumulate(ary.begin(),ary.end(),0.0,func);}
	template<size_t N> float accumulate(const array<float,N>&ary){return std::accumulate(ary.begin(),ary.end(),0.f);}
	template<size_t N,typename _Pr>float accumulate(const array<float,N>&ary,_Pr func){return std::accumulate(ary.begin(),ary.end(),0.f,func);}
	template<typename T,size_t N,typename _Pr>bool all_of(const array<T,N>&ary,_Pr pred){return std::all_of(ary.begin(),ary.end(),pred);}
	template<typename T,size_t N,typename _Pr>bool any_of(const array<T,N>&ary,_Pr pred){return std::any_of(ary.begin(),ary.end(),pred);}
	template<typename T,size_t N,typename _Pr>bool none_of(const array<T,N>&ary,_Pr pred){return std::none_of(ary.begin(),ary.end(),pred);}
	template<typename T,size_t N>const typename array<T,N>::const_iterator find(const array<T,N>&ary,const T& val){return std::find(ary.begin(),ary.end(),val);}
	template<typename T,size_t N,typename _Pr>const typename array<T,N>::const_iterator find_if(const array<T,N>&ary,_Pr pred){return std::find_if(ary.begin(),ary.end(),pred);}
	template<typename T,size_t N>bool contains(const array<T,N>&ary,const T& val){return std::find(ary.begin(),ary.end(),val)!=ary.end();}
	template<typename T,size_t N,typename _Pr>bool contains_if(const array<T,N>&ary,_Pr pred){return std::find_if(ary.begin(),ary.end(),pred) != ary.end();}
	template<typename T,size_t N,typename _Pr>typename iterator_traits<const typename array<T,N>::const_iterator>::difference_type count_if(const array<T,N>&ary,_Pr pred){return std::count_if(ary.begin(),ary.end(),pred);}
	template<typename T,size_t N>void sort(array<T,N>&ary){std::sort(ary.begin(),ary.end());}
	template<typename T,size_t N,typename _Pr>void sort(array<T,N>&ary,_Pr pred){std::sort(ary.begin(),ary.end(),pred);}
	template<typename T,size_t N>void stable_sort(array<T,N>&ary){std::stable_sort(ary.begin(),ary.end());}
	template<typename T,size_t N,typename _Pr>void stable_sort(array<T,N>&ary,_Pr pred){std::stable_sort(ary.begin(),ary.end(),pred);}

	template<typename Key, typename Value>
	bool containsKey(const umap<Key, Value>& m, const Key& key) {
		return m.find(key) != m.end();
	}
	template<typename Key, typename Value>
	bool containsValue(const umap<Key, Value>& m, const Value& val) {
		for (auto it = m.begin(); it != m.end(); ++it)
			if (it->second == val)
				return true;
		return false;
	}
	template<typename T>
	const typename uset<T>::const_iterator find(const uset<T>& s, const T& key) {
		return s.find(key);
	}
	template<typename T>
	bool contains(const uset<T>& s, const T& key) {
		return s.find(key) != s.end();
	}

	constexpr int DX4[] = {0, -1, 0, 1};
	constexpr int DY4[] = {-1, 0, 1, 0};
	constexpr int DX8[] = {0, -1, -1, -1, 0, 1, 1, 1};
	constexpr int DY8[] = {-1, -1, 0, 1, 1, 1, 0, -1};

	constexpr int DX5[] = {DX4[0], DX4[1], DX4[2], DX4[3], 0};
	constexpr int DY5[] = {DY4[0], DY4[1], DY4[2], DY4[3], 0};
	constexpr int DX9[] = {DX8[0], DX8[1], DX8[2], DX8[3], DX8[4], DX8[5], DX8[6], DX8[7], 0};
	constexpr int DY9[] = {DY8[0], DY8[1], DY8[2], DY8[3], DY8[4], DY8[5], DY8[6], DY8[7], 0};

	class Point {
	public:

		constexpr inline Point() : Point(-1, -1) {}
		constexpr inline Point(int x, int y) : x(x), y(y)	{}

		static Point getManhattanDist(const Point& p1, const Point& p2) {
			return move(Point(abs(p1.x - p2.x), abs(p1.y - p2.y))); 
		}

		void setPos(const Point& pos) { x = pos.x; y = pos.y; }
		void setPos(int x, int y) { this->x = x; this->y = y; }

		Point operator+ (int val) const { return move(Point(x + val, y + val)); }
		Point operator- (int val) const { return move(Point(x - val, y - val)); }
		Point operator* (int val) const { return move(Point(x * val, y * val)); }
		Point operator/ (int val) const { return move(Point(x / val, y / val)); }
		Point operator+ (const Point &p) const { return move(Point(x + p.x, y + p.y)); }
		Point operator- (const Point &p) const { return move(Point(x - p.x, y - p.y)); }
		Point operator* (const Point &p) const { return move(Point(x * p.x, y * p.y)); }
		Point operator/ (const Point &p) const { return move(Point(x / p.x, y / p.y)); }
		void operator+= (int val) { x += val; y += val; }
		void operator-= (int val) { x -= val; y -= val; }
		void operator*= (int val) { x *= val; y *= val; }
		void operator/= (int val) { x /= val; y /= val; }
		void operator+= (const Point &p) { x += p.x; y += p.y; }
		void operator-= (const Point &p) { x -= p.x; y -= p.y; }
		void operator*= (const Point &p) { x *= p.x; y *= p.y; }
		void operator/= (const Point &p) { x /= p.x; y /= p.y; }
		bool operator== (const Point &p) const { return x == p.x && y == p.y; }
		bool operator!= (const Point &p) const { return x != p.x || y != p.y; }
		//bool operator<(const Point &p) const {return x * x + y * y < p.x * p.x + p.y * p.y;}
		const Point& getPos() const { return *this; }

		string to_string() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

		int x, y;
	};

	constexpr Point DP4[] = {Point(DX4[0], DY4[0]), Point(DX4[1], DY4[1]), Point(DX4[2], DY4[2]), Point(DX4[3], DY4[3])};
	constexpr Point DP5[] = {Point(DX5[0], DY5[0]), Point(DX5[1], DY5[1]), Point(DX5[2], DY5[2]), Point(DX5[3], DY5[3]), Point(DX5[4], DY5[4])};
	constexpr Point DP8[] = {Point(DX8[0], DY8[0]), Point(DX8[1], DY8[1]), Point(DX8[2], DY8[2]), Point(DX8[3], DY8[3]), Point(DX8[4], DY8[4]), Point(DX8[5], DY8[5]), Point(DX8[6], DY8[6]), Point(DX8[7], DY8[7])};
	constexpr Point DP9[] = {Point(DX9[0], DY9[0]), Point(DX9[1], DY9[1]), Point(DX9[2], DY9[2]), Point(DX9[3], DY9[3]), Point(DX9[4], DY9[4]), Point(DX9[5], DY9[5]), Point(DX9[6], DY9[6]), Point(DX9[7], DY9[7])};

	// 定数時間初期化配列 (Constant Time Initializable Array)
	template<typename _Vt, size_t _Sz>
	class CTInitArray : public array<_Vt, _Sz> {
	public:
		CTInitArray() = default;
		CTInitArray(const _Vt& initVal) : mCurrentNum(1), mInitVal(initVal) { std::fill(mNums.begin(), mNums.end(), 0); }
		inline void setInitVal(const _Vt& initVal) { mInitVal = initVal; }
		inline void init() { ++mCurrentNum; }
		inline const _Vt& read(size_t index) const { return (mNums[index] == mCurrentNum) ? array<_Vt, _Sz>::operator[](index) : mInitVal; }
		inline const _Vt& write(size_t index, const _Vt& val) { mNums[index] = mCurrentNum; return array<_Vt, _Sz>::operator[](index) = val; }
	private:
		inline const _Vt& operator[](size_t index) const { return (mNums[index] == mCurrentNum) ? array<_Vt, _Sz>::operator[](index) : mInitVal; }
		_Vt mInitVal;
		array<int, _Sz> mNums;
		int mCurrentNum;
	};

	// 定数時間初期化配列２次元 (Constant Time Initializable Array)
	template<typename _Vt, size_t _Sz1, size_t _Sz2>
	class CTInitArray2D : public array<array<_Vt, _Sz2>, _Sz1> {
	public:
		CTInitArray2D() = default;
		CTInitArray2D(const _Vt& initVal) : mCurrentNum(1), mInitVal(initVal) { for (array<int, _Sz2>& t1 : mNums) std::fill(t1.begin(), t1.end(), 0); }
		inline void setInitVal(const _Vt& initVal) { mInitVal = initVal; }
		inline void init() { ++mCurrentNum; }
		inline const _Vt& read(size_t index1, size_t index2) { return (mNums[index1][index2] == mCurrentNum) ? array<array<_Vt, _Sz2>, _Sz1>::operator[](index1)[index2] : mInitVal; }
		inline const _Vt& write(size_t index1, size_t index2, const _Vt& val) { mNums[index1][index2] = mCurrentNum; return array<array<_Vt, _Sz2>, _Sz1>::operator[](index1)[index2] = val; }
	private:
		inline _Vt& operator[](size_t _Pos) { return array<array<_Vt, _Sz2>, _Sz1>::operator[](_Pos); } // 封印
		_Vt mInitVal;
		array<array<int, _Sz2>, _Sz1> mNums;
		int mCurrentNum;
	};

	// 定数時間初期化配列３次元 (Constant Time Initializable Array)
	template<typename _Vt, size_t _Sz1, size_t _Sz2, size_t _Sz3>
	class CTInitArray3D : public array<array<array<_Vt, _Sz3>, _Sz2>, _Sz1> {
	public:
		CTInitArray3D() = default;
		CTInitArray3D(const _Vt& initVal) : mCurrentNum(1), mInitVal(initVal) { for (array<array<int, _Sz3>, _Sz2>& t1 : mNums) for (array<int, _Sz3>& t2 : t1) std::fill(t2.begin(), t2.end(), 0); }
		inline void setInitVal(const _Vt& initVal) { mInitVal = initVal; }
		inline void init() { ++mCurrentNum; }
		inline const _Vt& read(size_t index1, size_t index2, size_t index3) { return (mNums[index1][index2][index3] == mCurrentNum) ? array<array<array<_Vt, _Sz3>, _Sz2>, _Sz1>::operator[](index1)[index2][index3] : mInitVal; }
		inline const _Vt& write(size_t index1, size_t index2, size_t index3, const _Vt& val) { mNums[index1][index2][index3] = mCurrentNum; return array<array<array<_Vt, _Sz3>, _Sz2>, _Sz1>::operator[](index1)[index2][index3] = val; }
	private:
		inline _Vt& operator[](size_t _Pos) { return array<array<array<_Vt, _Sz3>, _Sz2>, _Sz1>::operator[](_Pos); } // 封印
		_Vt mInitVal;
		array<array<array<int, _Sz3>, _Sz2>, _Sz1> mNums;
		int mCurrentNum;
	};

	static constexpr int COMBI_MAX = 500000; // nCrのnとrの最大値
	static ull gFact[COMBI_MAX + 1]; // modの世界での階乗
	static ull gInv[COMBI_MAX + 1]; // modの世界での逆元
	static ull gFactInv[COMBI_MAX + 1]; // modの世界での逆元の階乗
	static ull gCombiInitMod = 0; // 組み合わせの計算に使用したmod値

	namespace vmath {

		static constexpr ull mod_add(ull a, ull b, ull mod) {
			return ((a % mod) + (b % mod)) % mod;
		}

		static constexpr ull mod_sub(ull a, ull b, ull mod) {
			// a>bだとmod-(b-a)が返る
			return ((a % mod) + mod - (b % mod)) % mod;
		}

		static constexpr ull mod_mul(ull a, ull b, ull mod) {
			return ((a % mod) * (b % mod)) % mod;
		}

		// 最大公約数（ユーグリッドの互除法）
		static constexpr ull gcd(ull x, ull y) {
			assert(x > 0ull);
			assert(y > 0ull);
			ull r = 0ull;
			while ((r = x % y) != 0ull) {
				x = y;
				y = r;
			}
			return y;
		}

		// 最小公倍数
		static constexpr ull lcm(ull x, ull y) {
			assert(x > 0ull);
			assert(y > 0ull);

			return x / gcd(x, y) * y;
		}

		// 約数を全て求める O(√n)
		static ull calcDivisors(list<ull>* divisors, ull n) {
			divisors->clear();
			if (n <= 0ull) {
				return 0ull;
			}
			divisors->push_back(1ull);
			if (n != 1ull) {
				divisors->push_back(n);
			}
			for (ull i = 2ull; i * i <= n; ++i) {
				if (n % i == 0ull) {
					divisors->push_back(i);
					if (i != n / i) {
						divisors->push_back(n / i);
					}
				}
			}
			return divisors->size();
		}

		// 約数の個数を返す O(√n)
		static ull calcDivisorNum(ull n) {
			if (n <= 0ull) {
				return 0ull;
			}
			ull count = 1ull; // for 1
			if (n != 1ull) {
				++count; // for n
			}
			// for 2～n-1
			for (ull i = 2ull; i * i <= n; ++i) {
				if (n % i == 0ull) {
					count += 1ull;
					if (i != n / i) {
						count += 1ull;
					}
				}
			}
			return count;
		}

		// 素因数分解 O(√n)
		static int calcDecompositPrime(list<ull>* primes, ull n) {
			primes->clear();
			if (n == 0) {
				return 0ull;
			}
			if (n == 1) {
				primes->push_back(1);
				return 1ull;
			}
			// 割る数の初期値
			ull a = 2ull;
			// √n ≧ a ( n ≧ a * a ) の間ループ処理
			while (n >= a * a) {
				if (n % a == 0ull) {
					// a で割り切れたら、a は素因数
					primes->push_back(a);
					// そして、割られる数を a で割る
					n /= a;
				} else {
					// a で割り切れなかったら、 a を 1 増加させる
					a++;
				}
			}
			primes->push_back(n);
			return primes->size();
		}

		// 素因数の数を返す O(√n)
		static ull calcDecompositPrimeNum(ull n) {
			if (n <= 1) {
				return n;
			}
			ull count = 0ull;
			// 割る数の初期値
			ull a = 2ull;
			// √n ≧ a ( n ≧ a * a ) の間ループ処理
			while (n >= a * a) {
				if (n % a == 0ull) {
					// a で割り切れたら、a は素因数
					++count;
					// そして、割られる数を a で割る
					n /= a;
				} else {
					// a で割り切れなかったら、 a を 1 増加させる
					a++;
				}
			}
			++count; // for n
			return count;
		}

		// 階乗
		static constexpr ull fact(ull x, ull mod) {
			ull result = 1ull;
			for (ull i = 1ull; i <= x; ++i) {
				if (mod == 0ull) {
					result *= i;
				} else {
					result = mod_mul(result, i, mod);
				}
			}
			return result;
		}
		// 階乗
		static constexpr ull fact(ull x) {
			return fact(x, 0ull);
		}

		// 順列の個数 nPr
		static constexpr ull permutation(ull n, ull r, ull mod) {
			assert(n >= r);
			if (n == 0ull || r == 0ull) {
				return 0ull;
			}
			//return fact(n) / fact(n - r);
			ull result = 1ull;
			for (ull i = n; i > n - r; --i) {
				if (mod == 0ull) {
					result *= i;
				} else {
					result = mod_mul(result, i, mod);
				}
			}
			return result;
		}
		// 順列の個数 nPr
		static constexpr ull permutation(ull n, ull r) {
			return permutation(n, r, 0ull);
		}

		// 組み合わせテーブルを作る
		static void initCombination(ull mod) {
			gFact[0] = gFact[1] = 1;
			gFactInv[0] = gFactInv[1] = 1;
			gInv[1] = 1;
			for (int i = 2; i <= COMBI_MAX; i++){
				gFact[i] = gFact[i - 1] * i % mod;
				gInv[i] = mod - gInv[mod%i] * (mod / i) % mod;
				gFactInv[i] = gFactInv[i - 1] * gInv[i] % mod;
			}
			gCombiInitMod = mod;
		}
		static void initCombination() {
			initCombination(V_MOD);
		}

		// 組み合わせの数を計算
		static long long combination(ull n, ull k) {
			assert(gCombiInitMod > 0 && "先にinitCombinationを呼び出して");
			assert(n <= (ull)COMBI_MAX);
			assert(k <= (ull)COMBI_MAX);
			if (n < k) return 0;
			return (gFact[n] * ((gFactInv[k] * gFactInv[n - k]) % V_MOD)) % V_MOD;
		}

		// 重複組合せ nHr = n+r-1Cr
		// 使いどころ：n人にr個を配るとき、同じ人に何個配っても良い場合とか
		// 4人に5個の◯を配るときa=2,b=0,c=2,d=1のとき、◯◯||◯◯|◯みたいになる。
		// これは◯と|を混ぜた組み合わせで、◯の数がn,棒の数はr-1だから全体でn+r-1
		// (n-r)で割ったものが順列n+r-1Prで、それを更にrで割っているからnHr = n+r-1Cr
		static ull repeatedCombination(ull n, ull r) {
			return combination(n + r - 1, r);
		}

		// xのN乗を求める(バイナリ法) O(logN)
		static constexpr ull intPow(ull x, ull n, ull mod) {
			assert(x >= 0ull);
			assert(n >= 0ull);
			if (x == 0ull) {
				if (n == 0ull) {
					return 1ull;
				} else {
					return 0ull;
				}
			}
			ull result = 1ull;
			ull z = x;
			while (n > 0ull) {
				if (n & 1ull) {
					if (mod > 0ull) {
						result = mod_mul(result, z, mod);
					} else {
						result *= z;
					}
				}
				if (mod > 0ull) {
					z = mod_mul(z, z, mod);
				} else {
					z *= z;
				}
				n >>= 1ull;
			}
			return result;
		}
		// xのN乗を求める(バイナリ法) O(logN)
		static constexpr ull intPow(ull x, ull n) {
			return intPow(x, n, 0ull);
		}

		// xのN桁目の数値を得る
		static constexpr ull getNDigitNumber(ull x, ull n) {
			assert(n > 0);
			assert(n <= 20);
			return (x / intPow(10ull, n - 1ull)) % 10;
		}

	};

	class vegde {
	public:
		vegde() : vegde(-1) {

		}

		vegde(int cost) :
			mCost(cost) {

		}

		int getCost() const { return mCost; }

	private:
		int mCost;
	};

	class vnode {
	public:
		vnode() : vnode(-1) {

		}

		vnode(int id) :
			mID(id) {

		}

		void addEgde(const vegde& egde, const vnode* node) {
			mEgdeList.emplace_back(egde, node);
		}
		void removeEgde(int nodeID) {
			auto itrNewEnd = std::remove_if(mEgdeList.begin(), mEgdeList.end(), [=](const pair<vegde, const vnode*>& p)->bool {
				return (p.second->getID() == nodeID);
			});
			mEgdeList.erase(itrNewEnd, mEgdeList.end());
		}

		int getID() const { return mID; }
		const list<pair<vegde, const vnode*>>& getEgde() const { return mEgdeList; }
	private:
		list<pair<vegde, const vnode*>> mEgdeList;
		int mID;
	};

	class AdjacencyMatrix {
	public:

		AdjacencyMatrix() = default;

		AdjacencyMatrix(int nodeNum) {
			resize(mConnectionMap, nodeNum, nodeNum);
			resize(mCostMap, nodeNum, nodeNum);
			resize(mMinimumDistMap, nodeNum, nodeNum);
		}

		//virtual void addEdge(int nodeID1, int nodeID2, int cost) = 0;
		//virtual void removeEgde(int nodeID1, int nodeID2) = 0;

		void warshallFloyd(int nodeNum) {
			for (int k = 0; k < nodeNum; ++k) {
				for (int i = 0; i < nodeNum; ++i) {
					for (int j = 0; j < nodeNum; ++j) {
						if (mConnectionMap[i][j]) {
							mMinimumDistMap[i][j] = mCostMap[i][j];
						} else {
							mMinimumDistMap[i][j] = 99999999;
						}
					}
				}
			}
			for (int k = 0; k < nodeNum; ++k) {
				for (int i = 0; i < nodeNum; ++i) {
					for (int j = 0; j < nodeNum; ++j) {
						mMinimumDistMap[i][j] = min(mMinimumDistMap[i][j], mMinimumDistMap[i][k] + mMinimumDistMap[k][j]);
					}
				}
			}
			//for (int i = 0; i < mNodeNum; ++i) {
			//	for (int j = 0; j < mNodeNum; ++j) {
			//		cerr << mMinimumDistMap[i][j] << ", ";
			//	}
			//	cerr << endl;
			//}
		}

		const vector<vector<bool>>& getConnectionMap() const { return mConnectionMap; }
		const vector<vector<int>>& getCostMap() const { return mCostMap; }

		const vector<vector<int>>& getMinimumDistMap() const { return mMinimumDistMap; }

	protected:
		vector<vector<bool>> mConnectionMap;
		vector<vector<int>> mCostMap;

		vector<vector<int>> mMinimumDistMap;
	};

	class DirectedAdjacencyMatrix : public AdjacencyMatrix  {
	public:

		DirectedAdjacencyMatrix() = default;

		DirectedAdjacencyMatrix(int nodeNum) :
			AdjacencyMatrix(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mConnectionMap[nodeID1][nodeID2] = true;
			mCostMap[nodeID1][nodeID2] = cost;
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mConnectionMap[nodeID1][nodeID2] = false;
			mCostMap[nodeID1][nodeID2] = 0;
		}
	};

	class UndirectedAdjacencyMatrix : public AdjacencyMatrix {
	public:

		UndirectedAdjacencyMatrix() = default;

		UndirectedAdjacencyMatrix(int nodeNum) :
			AdjacencyMatrix(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mConnectionMap[nodeID1][nodeID2] = true;
			mConnectionMap[nodeID2][nodeID1] = true;
			mCostMap[nodeID1][nodeID2] = cost;
			mCostMap[nodeID2][nodeID1] = cost;
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mConnectionMap[nodeID1][nodeID2] = false;
			mConnectionMap[nodeID2][nodeID1] = false;
			mCostMap[nodeID1][nodeID2] = 0;
			mCostMap[nodeID2][nodeID1] = 0;
		}

	};

	// グラフ
	class vgraph {
	public:

		const int INF = 1000000;

		vgraph(int nodeNum) {
			mNodeNum = nodeNum;
			mNodes.resize(nodeNum);
			for (int i = 0; i < nodeNum; ++i) {
				mNodes[i] = move(vnode(i));
			}
			mMinimumDists.resize(mNodeNum);
			mPrevNodes.resize(mNodeNum);
		}

		void addEgde(int nodeID1, int nodeID2) {
			addEgde(nodeID1, nodeID2, 1);
		}

		virtual void addEgde(int nodeID1, int nodeID2, int cost) = 0;
		virtual void removeEgde(int nodeID1, int nodeID2) = 0;

		int dfs(int start) {
			vector<bool> check(mNodes.size());
			fill(check, false);
			int MAX_DEPTH = INF; // 探索の深さ制限があれば定義する
			return dfsSub(start, check, MAX_DEPTH, 0);
		}

		void bfs(int start) {
			vector<bool> check(mNodes.size());
			fill(check, false);
			int MAX_DEPTH = INF; // 探索の深さ制限があれば定義する
			return bfsSub(start, check, MAX_DEPTH);
		}

		// ベルマンフォード法を使ってある頂点から全ての頂点への最短距離を求める
		// startからたどり着ける場所に負のループが存在する場合はfalseを返す
		// ダイクストラ法と違い、負のコストの辺があっても最短距離を計算できる
		// O(V*E)
		bool bellmanFord(int start) {

			vector<int>& dist = mMinimumDists;

			fill(dist, INF);
			dist[start] = 0;

			for (int i = 0; i < mNodeNum; ++i) {
				bool update = false;
				for (vnode node : mNodes) {
					for (const pair<vegde, const vnode*> egde : node.getEgde()) {
						int from = node.getID();
						int to = egde.second->getID();
						if (dist[from] == INF) {
							continue;
						}
						if (dist[from] + egde.first.getCost() < dist[to]) {
							dist[to] = dist[from] + egde.first.getCost();
							update = true;

							if (i == mNodeNum - 1) {
								//return false;
							}
						}
					}
				}
				if (!update) {
					break;
				}
			}
			return true;
		}

		// ダイクストラ法を使ってある頂点から全ての頂点への最短距離を求める
		// 負のコストの辺があると最短距離を計算できない点に注意する
		// O(E*logV)
		void dijkstraSearch(int start) {

			// Minimum distances for each nodes
			vector<int>& dpMinDists = mMinimumDists;
			fill(dpMinDists, INF);

			// Result of the previous visited node
			vector<int>& resultPrev = mPrevNodes;
			fill(resultPrev, -1);

			// Create a priority_queue for search.
			typedef pair<int, int> P; // key: その頂点までの最短距離, value: 頂点の番号
			priority_queue<P, vector<P>, greater<P>> pq_node;

			// Mark the current node as visited and enqueue it
			pq_node.push(P(0, start));

			dpMinDists[start] = 0;

			while (!pq_node.empty()) {
				P p = pq_node.top();
				pq_node.pop();
				int nowDist = p.first;
				int nowNodeID = p.second;

				if (dpMinDists[nowNodeID] < nowDist) {
					continue;
				}

				for (const pair<vegde, const vnode*>& egde : mNodes[nowNodeID].getEgde()) {
					const vnode* nextNode = egde.second;
					int nextNodeID = nextNode->getID();

					int nextNodeDist = nowDist + egde.first.getCost();
					if (nextNodeDist < dpMinDists[nextNodeID]) {
						dpMinDists[nextNodeID] = nextNodeDist;
						resultPrev[nextNodeID] = nowNodeID;

						pq_node.push(P(nextNodeDist, nextNodeID));
					}
				}
			}
		}

		int calcMaxDepth() const {
			pair<int, int> farestNodeData = getFarestNodeID(0);
			pair<int, int> farestNodeData2 = getFarestNodeID(farestNodeData.first);
			return farestNodeData2.second;
		}

		int getNodeNum() const { return mNodeNum; }
		const vector<vnode>& getNodes() const { return mNodes; }

		const vector<int>& getMinimumDists() const { return mMinimumDists; }
		const vector<int>& getPrevNodes() const { return mPrevNodes; }
	protected:

		int dfsSub(int nodeIndex, vector<bool>& check, int MAX_DEPTH, int depth) {
			check[nodeIndex] = true;
			int result = 0;

			// 隣接する辺を探索
			if (depth < MAX_DEPTH) {
				for (const auto& t : mNodes[nodeIndex].getEgde()) {
					if (check[t.second->getID()]) {
						// 巡回済みの辺は見ない
						continue;
					}
					result += dfsSub(t.second->getID(), check, MAX_DEPTH, depth + 1);
				}
			}

			// 末端での処理
			result += 1; // この巡回順で末端に辿り着いた時、目的の条件を満たすなら+1する


			check[nodeIndex] = false;

			return result;
		}

		void bfsSub(int start, vector<bool>& check, int MAX_DEPTH) {

			queue<pair<int, int>> target;
			target.push(pair<int, int>(start, 0));
			while (!target.empty()) {
				pair<int, int> now = target.front();
				target.pop();

				// ノードに対して何かやることがあればここでやる
				//mNodes[now.first].something = someData;

				check[now.first] = true;
				int egdeCount = 0;
				if (now.second < MAX_DEPTH) {
					for (const pair<vegde, const vnode*>& egde : mNodes[now.first].getEgde()) {
						if (check[egde.second->getID()]) {
							// このノードはもっと少ない手順で巡回可能なので行かない
							continue;
						}
						++egdeCount;
						target.push(pair<int, int>(egde.second->getID(), now.second + 1));
					}
				}
				if (now.second == MAX_DEPTH || egdeCount == 0) {
					// 探索深さ制限またはこのノードから繋がる辺が全て巡回済み

					// doSomething.

				}
			}
		}

		// 引数で受け取ったノードから最も遠いノードのidと距離を返す
		// グラフにループがあると無限ループになるので注意する(つまり木専用)
		pair<int, int> getFarestNodeID(int start) const {
			queue<pair<int, int>> q; // nodeID, このノードまでの距離
			q.push(make_pair(start, 0));
			pair<int, int> finalNodeData;
			vector<bool> opened(mNodeNum);
			fill(opened, false);
			while (!q.empty()) {
				pair<int, int> nodeData = q.front();
				int nodeID = nodeData.first;
				int dist = nodeData.second;
				if (dist > finalNodeData.second) {
					finalNodeData.second = dist;
					finalNodeData.first = nodeID;
				}
				q.pop();
				for (const pair<vegde, const vnode*> egde : mNodes[nodeID].getEgde()) {
					int id = egde.second->getID();
					if (opened[id]) {
						continue;
					}
					opened[id] = true;
					q.push(make_pair(id, dist + egde.first.getCost()));
				}
			}
			return finalNodeData;
		}

		int mNodeNum;
		bool mUseMaps;
		vector<vnode> mNodes;

		vector<int> mMinimumDists;
		vector<int> mPrevNodes;
	};

	// 無向グラフ UnDirected Val Graph.
	class udvgraph : public vgraph {
	public:
		udvgraph(int nodeNum) :
			vgraph(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mNodes[nodeID1].addEgde(move(vegde(cost)), &mNodes[nodeID2]);
			mNodes[nodeID2].addEgde(move(vegde(cost)), &mNodes[nodeID1]);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mNodes[nodeID1].removeEgde(nodeID2);
			mNodes[nodeID2].removeEgde(nodeID1);
		}
	};

	// 隣接行列付きの無向グラフ。ワーシャルフロイドが使える。 UnDirected Val Graph Matrix
	class udvgraph_m : public udvgraph {
	public:

		udvgraph_m(int nodeNum) :
			udvgraph(nodeNum) {
			mAdjacencyMatrix = UndirectedAdjacencyMatrix(nodeNum);
		}
		void addEgde(int nodeID1, int nodeID2, int cost) {
			udvgraph::addEgde(nodeID1, nodeID2, cost);
			mAdjacencyMatrix.addEgde(nodeID1, nodeID2, cost);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			udvgraph::removeEgde(nodeID1, nodeID2);
			mAdjacencyMatrix.removeEgde(nodeID1, nodeID2);
		}

		void warshallFloyd() {
			mAdjacencyMatrix.warshallFloyd(mNodeNum);
		}

		const vector<vector<bool>>& getConnectionMap() const { return mAdjacencyMatrix.getConnectionMap(); }
		const vector<vector<int>>& getCostMap() const { return mAdjacencyMatrix.getCostMap(); }

		const vector<vector<int>>& getMinimumDistMap() const { return mAdjacencyMatrix.getMinimumDistMap(); }
	private:
		UndirectedAdjacencyMatrix mAdjacencyMatrix;
	};


	// 有向グラフ Directed Val Graph.
	class dvgraph : public vgraph {
	public:
		dvgraph(int nodeNum) :
			vgraph(nodeNum) {
		}

		void addEgde(int nodeID1, int nodeID2, int cost) {
			mNodes[nodeID1].addEgde(move(vegde(cost)),&mNodes[nodeID2]);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			mNodes[nodeID1].removeEgde(nodeID2);
		}

		// 入力のないノードのリストを返す
		list<int> searchStartNodes() const {
			list<int> startNodes;
			unordered_map<int, int> nodesInputs; // key:ノード番号, value:インプット数
			for (auto node : mNodes) {
				for (auto edge : node.getEgde()) {
					++nodesInputs[edge.second->getID()];
				}
			}
			for (int i = 0; i < mNodeNum; ++i) {
				if (nodesInputs.find(i) == nodesInputs.end()) {
					startNodes.push_back(i);
				}
			}
			return move(startNodes);
		}
	};

	// 隣接行列付きの有向グラフ。ワーシャルフロイドが使える。 Directed Val Graph Matrix
	class dvgraph_m : public dvgraph {
	public:

		dvgraph_m(int nodeNum) :
			dvgraph(nodeNum) {
			mAdjacencyMatrix = DirectedAdjacencyMatrix(nodeNum);
		}
		void addEgde(int nodeID1, int nodeID2, int cost) {
			dvgraph::addEgde(nodeID1, nodeID2, cost);
			mAdjacencyMatrix.addEgde(nodeID1, nodeID2, cost);
		}

		void removeEgde(int nodeID1, int nodeID2) {
			dvgraph::removeEgde(nodeID1, nodeID2);
			mAdjacencyMatrix.removeEgde(nodeID1, nodeID2);
		}

		void warshallFloyd() {
			mAdjacencyMatrix.warshallFloyd(mNodeNum);
		}

		const vector<vector<bool>>& getConnectionMap() const { return mAdjacencyMatrix.getConnectionMap(); }
		const vector<vector<int>>& getCostMap() const { return mAdjacencyMatrix.getCostMap(); }

		const vector<vector<int>>& getMinimumDistMap() const { return mAdjacencyMatrix.getMinimumDistMap(); }
	private:
		DirectedAdjacencyMatrix mAdjacencyMatrix;
	};

	// 立っているビットの数を返す
	static constexpr int bitcount8(unsigned char b8) {
		// 8 bits 限定アルゴリズムを利用している
		//c_assert( 8 == (CHAR_BIT * sizeof( b8 )) );

		b8 = (unsigned char)( ((b8 & 0xAA) >> 1) + (b8 & 0x55) );
		b8 = (unsigned char)( ((b8 & 0xCC) >> 2) + (b8 & 0x33) );
		b8 = (unsigned char)( ((b8 & 0xF0) >> 4) + (b8 & 0x0F) );

		return b8;
	}

	// 立っているビットの数を返す
	static constexpr int bitcount16(unsigned short w16) {
		// 16 bits 限定アルゴリズムを利用している
		//c_assert( 16 == (CHAR_BIT * sizeof( w16 )) );

		w16 = (unsigned short)( ((w16 & 0xAAAA) >> 1) + (w16 & 0x5555) );
		w16 = (unsigned short)( ((w16 & 0xCCCC) >> 2) + (w16 & 0x3333) );
		w16 = (unsigned short)( ((w16 & 0xF0F0) >> 4) + (w16 & 0x0F0F) );
		w16 = (unsigned short)( ((w16 & 0xFF00) >> 8) + (w16 & 0x00FF) );

		return w16;
	}

	// 立っているビットの数を返す
	static constexpr int bitcount32(unsigned long dw32) {
		// 32 bits 限定アルゴリズムを利用している
		//c_assert( 32 == (CHAR_BIT * sizeof( dw32 )) );

		dw32 = ((dw32 & 0xAAAAAAAA) >>  1) + (dw32 & 0x55555555);
		dw32 = ((dw32 & 0xCCCCCCCC) >>  2) + (dw32 & 0x33333333);
		dw32 = ((dw32 & 0xF0F0F0F0) >>  4) + (dw32 & 0x0F0F0F0F);
		dw32 = ((dw32 & 0xFF00FF00) >>  8) + (dw32 & 0x00FF00FF);
		dw32 = ((dw32 & 0xFFFF0000) >> 16) + (dw32 & 0x0000FFFF);

		return dw32;
	}

	// 条件を満たす最小の要素のindexを返す
	// 存在しない場合は-1を返す
	// 使い方の例: int result = binarySearch<int>(A, 0, N - 1, [&](int x) { return x >= K; });
	template<typename T> int binarySearch(const vector<T>& vec, int beginIndex, int endIndex, const function<bool(const T&)>& confilm) {
		// 解が両端にある場合や解なしの判定のために、両端の１つ外側から始める
		int lb = beginIndex - 1; // lower bound
		int ub = endIndex + 1; // upper bound

		while (ub - lb > 1) {
			int mid = (ub + lb) / 2;
			if (confilm(vec[mid])) {
				ub = mid;
			} else {
				lb = mid;
			}
		}

		if (ub == endIndex + 1) {
			// 解なし
			return -1;
		}

		return ub;
	}

	// 文字列の先頭の0を削除する
	string cutZeroLeft(const string& str) {
		for (int i = 0; i < (int)str.length(); ++i) {
			if (str[i] != '0') {
				return str.substr(i);
			}
		}
		return "";
	}

	// 0以上の整数を0埋めで表記する
	string fillZero(ull number, int digit) {
		int zeroNum = max(0, (int)(digit - to_string(number).length()));
		return move(move(string(zeroNum, '0')) + move(to_string(number)));
	}

	// 0以上の10進数を2進数に変換する
	string toBinString(ull x) {
		return move(cutZeroLeft(bitset<20>(x).to_string()));
	}

	// 0以上の10進数を8進数に変換する
	string toOctString(ull x) {
		stringstream ss;
		ss << std::oct << x;
		return move(ss.str());
	}

	// 0以上の整数を16進数に変換する(a～fは小文字)
	string toHexString(ull x) {
		stringstream ss;
		ss << std::hex << x;
		return move(ss.str());
	}

	// 0以上の整数を任意の基数に変換する(最大36進数)(a～zは小文字)
	string toBaseString(ull x, int base) {
		const string table = "0123456789abcdefghijklmnopqrstuvwxyz";

		assert(base >= 2 && base <= 36);

		string result = "";
		ull y = x;
		do {
			ull div = y / (ull)base;
			int mod = y % (ull)base;

			result = table[mod] + result;
			y = div;
		}
		while (y != 0ull);

		return move(result);
	}

	// 任意の基数の0以上の整数を10進数に変換する
	// base: 変換元の基数
	ull toDecimal(string numberString, int base) {
		assert(numberString.length() < 20);
		assert(!numberString.empty());
		return stoull(numberString, nullptr, base);
	}

	// double型の値を任意の少数桁数で表示する
	// 指定の桁数まで0で埋める。指数表記にはならない
	// precision=0を指定したときは小数点は表示しない
	// 表示桁数＋１桁目を四捨五入する
	string sprintDoublePlane(double value, int precision) {
		assert(precision >= 0);
		stringstream ss;
		ss << fixed << setprecision(precision) << value;
		return move(ss.str());
	}

	class Grid {
	public:
		static const int INF = 1000000;
		static const int MAX_H = 100;
		static const int MAX_W = 100;

		struct SchElem {
		public:
			SchElem(const Point& pos, int dist) :
				pos(pos), dist(dist) {
			}

			Point pos;
			int dist;
		};

		vector<vector<char>> mGrid;
		//CTInitArray2D<bool, H, W>
		int mW, mH;

		Grid() = default;

		Grid(int w, int h) :
			mW(w), mH(h) {
			mGrid.resize(mH, vector<char>(mW, '\0'));
		}

		void input() {
			for (int y = 0; y < mH; ++y) {
				for (int x = 0; x < mW; ++x) {
					cin >> mGrid[y][x];
				}
				cin.ignore();
			}
		}

		bool isOutOfGrid(const Point& p) const {
			return p.x < 0 || p.y < 0 || p.x >= mW || p.y >= mH;
		}

		bool canMove(int x, int y) const {
			// 問題固有条件
			return true;
			//return mGrid[y][x] != '#';
		}
		bool canMove(const Point& p) const {
			return canMove(p.x, p.y);
		}

		int dfs(int x, int y) {
			static CTInitArray2D<bool, MAX_H, MAX_W> check(false);
			check.init();
			const int MAX_DEPTH = INF; // 探索の深さ制限があれば定義する

			int result = 0;

			stack<SchElem> target;
			target.push(SchElem(Point(x, y), 0));
			check.write(y, x, true);

			while (!target.empty()) {
				SchElem now = target.top();
				target.pop();

				// セルに対して何かやることがあればここでやる
				//if (now.pos.x == someTargetX && now.pos.y == someTargetY) {
				//	result = 1;
				//}

				int nextCount = 0;
				if (now.dist < MAX_DEPTH) {
					for (int i = 0; i < 4; ++i) {
						Point next = now.pos + DP4[i];
						if (isOutOfGrid(next)) {
							continue;
						}
						if (check.read(next.y, next.x)) {
							// この場所はもっと少ない手順で到達可能なので行かない
							continue;
						}
						if (!canMove(next)) {
							// 移動不可のセルには移動しない
							continue;
						}
						++nextCount;
						target.push(SchElem(next, now.dist + 1));
						check.write(next.y, next.x, true);
					}
				}
				if (now.dist == MAX_DEPTH || nextCount == 0) {
					// 末端での処理

					// doSomething.

				}
			}

			return result;
		}
		
		int bfs(int x, int y) {
			static CTInitArray2D<bool, MAX_H, MAX_W> check(false);
			check.init();
			const int MAX_DEPTH = INF; // 探索の深さ制限があれば定義する

			int result = MAX_DEPTH;

			queue<SchElem> target;
			target.push(SchElem(Point(x, y), 0));
			check.write(y, x, true);

			while (!target.empty()) {
				SchElem now = target.front();
				target.pop();

				// セルに対して何かやることがあればここでやる
				//if (now.pos.x == someTargetX && now.pos.y == someTargetY) {
				//	result = min(result, now.dist);
				//}

				int nextCount = 0;
				if (now.dist < MAX_DEPTH) {
					for (int i = 0; i < 4; ++i) {
						Point next = now.pos + DP4[i];
						if (isOutOfGrid(next)) {
							continue;
						}
						if (check.read(next.y, next.x)) {
							// この場所はもっと少ない手順で到達可能なので行かない
							continue;
						}
						if (!canMove(next)) {
							// 移動不可のセルには移動しない
							continue;
						}
						++nextCount;
						target.push(SchElem(next, now.dist + 1));
						check.write(next.y, next.x, true);
					}
				}
				if (now.dist == MAX_DEPTH || nextCount == 0) {
					// 探索深さ制限またはこのノードから繋がる辺が全て巡回済み

					// doSomething.

				}
			}

			return result;
		}

	};

	template<typename A>void in(A&a){cin>>a;cin.ignore();}
	template<typename A,typename B>void in(A&a,B&b){cin>>a>>b;cin.ignore();}
	template<typename A,typename B,typename C>void in(A&a,B&b,C&c){cin>>a>>b>>c;cin.ignore();}
	template<typename A,typename B,typename C,typename D>void in(A&a,B&b,C&c,D&d){cin>>a>>b>>c>>d;cin.ignore();}
	template<typename A,typename B,typename C,typename D,typename E>void in(A&a,B&b,C&c,D&d,E&e){cin>>a>>b>>c>>d>>e;cin.ignore();}
	template<typename A,typename B,typename C,typename D,typename E,typename F>void in(A&a,B&b,C&c,D&d,E&e,F&f){cin>>a>>b>>c>>d>>e>>f;cin.ignore();}
	template<typename A,typename B,typename C,typename D,typename E,typename F,typename G>void in(A&a,B&b,C&c,D&d,E&e,F&f,G&g){cin>>a>>b>>c>>d>>e>>f>>g;cin.ignore();}

	template<typename A>
	void inr(vector<A>& a, int size) {
		resize(a, size);
		for (int i = 0; i < size; ++i) {
			cin >> a[i]; cin.ignore();
		}
	}
	template<typename A, typename B>
	void inr(vector<A>& a, vector<B>& b, int size) {
		resize(a, size); resize(b, size);
		for (int i = 0; i < size; ++i) {
			cin >> a[i] >> b[i]; cin.ignore();
		}
	}
	template<typename A, typename B, typename C>
	void inr(vector<A>& a, vector<B>& b, vector<C>& c, int size) {
		resize(a, size); resize(b, size); resize(c, size);
		for (int i = 0; i < size; ++i) {
			cin >> a[i] >> b[i] >> c[i]; cin.ignore();
		}
	}
	template<typename A, typename B, typename C, typename D>
	void inr(vector<A>& a, vector<B>& b, vector<C>& c, vector<D>& d, int size) {
		resize(a, size); resize(b, size); resize(c, size); resize(d, size);
		for (int i = 0; i < size; ++i) {
			cin >> a[i] >> b[i] >> c[i] >> d[i]; cin.ignore();
		}
	}
	template<typename A, typename B, typename C, typename D, typename E>
	void inr(vector<A>& a, vector<B>& b, vector<C>& c, vector<D>& d, vector<E>& e, int size) {
		resize(a, size); resize(b, size); resize(c, size); resize(d, size); resize(e, size);
		for (int i = 0; i < size; ++i) {
			cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i]; cin.ignore();
		}
	}

	template<typename A>
	void inr(vector<vector<A>>& a, int h, int wa) {
		resize(a, h, wa);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < wa; ++j) {
				cin >> a[i][j];
			}
			cin.ignore();
		}
	}
	template<typename A,typename B>
	void inr(vector<vector<A>>& a, vector<vector<B>>& b, int h, int wa, int wb) {
		resize(a, h, wa); resize(b, h, wb);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < wa; ++j) {
				cin >> a[i][j];
			}
			for (int j = 0; j < wb; ++j) {
				cin >> b[i][j];
			}
			cin.ignore();
		}
	}
	template<typename A,typename B,typename C>
	void inr(vector<vector<A>>& a, vector<vector<B>>& b, vector<vector<C>>& c, int h, int wa, int wb, int wc) {
		resize(a, h, wa); resize(b, h, wb); resize(c, h, wc);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < wa; ++j) {
				cin >> a[i][j];
			}
			for (int j = 0; j < wb; ++j) {
				cin >> b[i][j];
			}
			for (int j = 0; j < wc; ++j) {
				cin >> c[i][j];
			}
			cin.ignore();
		}
	}

	template<typename T>
	void out(const T& val) { cout << val << endl; }
}

using namespace ValLib;
using namespace vmath;

int main() {

	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB") {
		out("No");
	} else {
		out("Yes");
	}

}
