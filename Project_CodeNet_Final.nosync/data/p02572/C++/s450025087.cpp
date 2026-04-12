#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

template<long long sz = 1000000007LL>
struct ModInt{
private:
	long long value;
	inline ModInt<sz> mpow(ModInt<sz> a, long long b){
		if (b == 0) return ModInt<sz>(1);
		ModInt<sz> tmp = mpow(a, b / 2);
		if (b % 2) return tmp * tmp * a;
		return tmp * tmp;
	}
public:
	ModInt(long long value = 0) : value((value % sz + sz) % sz) {}
	long long get(void) { return this->value; }
	constexpr ModInt<sz> operator+ (ModInt<sz> obj){
		return ModInt<sz>(this->value + obj.get());
	}
	constexpr ModInt<sz> operator+ (long long obj){ return (*this) + ModInt<sz>(obj); }
	constexpr ModInt<sz> operator- (ModInt<sz> obj){
		return ModInt<sz>((this->value - obj.get() + sz) % sz);
	}
	constexpr ModInt<sz> operator- (long long obj){ return (*this) - ModInt<sz>(obj); }
	constexpr ModInt<sz> operator* (ModInt<sz> obj){
		return ModInt<sz>(this->value * obj.get() % sz);
	}
	constexpr ModInt<sz> operator* (long long obj){ return (*this) * ModInt<sz>(obj); }
	constexpr ModInt<sz> operator/ (ModInt<sz> obj){
		return (*this) * mpow(obj, sz - 2);
	}
	constexpr ModInt<sz> operator/ (long long obj){ return (*this) / ModInt<sz>(obj); }
	constexpr ModInt<sz>& operator+= (ModInt<sz> obj){
		return *this = (*this) + obj;
	}
	constexpr ModInt<sz>& operator+= (long long obj){
		return *this = (*this) + obj;
	}
	constexpr ModInt<sz>& operator-= (ModInt<sz> obj){
		return *this = (*this) - obj;
	}
	constexpr ModInt<sz>& operator-= (long long obj){
		return *this = (*this) - obj;
	}
	constexpr ModInt<sz>& operator*= (ModInt<sz> obj){
		return *this = (*this) * obj;
	}
	constexpr ModInt<sz>& operator*= (long long obj){
		return *this = (*this) * obj;
	}
	constexpr ModInt<sz>& operator/= (ModInt<sz> obj){
		return *this = (*this) / obj;
	}
	constexpr ModInt<sz>& operator/= (long long obj){
		return *this = (*this) / obj;
	}
	ModInt<sz> pow(long long a){ return mpow(*this, a); }
	friend constexpr ostream& operator<< (ostream& os, const ModInt<sz>& data){
		return os << data.value;
	}
};

int main(void){
	int N; cin >> N;
	ModInt<> sum(0), sum2(0);
	while (N--){
		ll ai; cin >> ai;
		ModInt<> tmp(ai);
		sum += tmp;
		sum2 += tmp * tmp;
	}
	ModInt<> res = (sum * sum - sum2) / ModInt<>(2);
	cout << res << endl;
	return 0;
}