#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define UB upper_bound
#define LB lower_bound
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

typedef long long unsigned int LLUI;

class Permutation {
public:
	Permutation(int size);
	LLUI get_counter();
	int get_at(int n);
	void set_permutation(LLUI n);
	bool next_permutation();
	bool previous_permutation();
	
private:
	int size;
	int a[20];
	LLUI counter;
	LLUI frac(LLUI n) {
		if(n == 0) { return 1; }
		return n * frac(n - 1);
	}
	void swap(int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	void reverse(int i, int j) { // 閉区間
		for(int k = i, l = j;  k < l;  k++, l--) { swap(k, l); }
	}
};

Permutation::Permutation(int size) {
	counter = 0;
	for(int i = 0; i < size; i++) { a[i] = i; }
	this -> size = size;
}

LLUI Permutation::get_counter() {
	return counter;
}

int Permutation::get_at(int n) {
	return a[n];
}

void Permutation::set_permutation(LLUI n) {
	counter = n;
	
	LLUI f[20];
	bool enable[20];
	f[0] = 1;
	for(int i = 1; i < size; i++) {
		f[i] = f[i - 1] * i;
		enable[i] = true;
	}
	
	for(int i = size - 1; 0 <= i; i--) {
		int p = n / f[i], c = 0, j = 0;
		while(true) {
			c += (enable[j] ? 1 : 0);
			if(c == p + 1) { break; }
			j++;
		}
		enable[j] = false;
		a[size - 1 - i] = j;
		n %= f[i];
	}
	
	return;
}

bool Permutation::next_permutation() {
	for(int i = size - 2; 0 <= i; i--) {
		if(a[i] < a[i + 1]) {
			int j = size - 1;
			while(a[i] > a[j]) { j--; }
			swap(i, j);
			reverse(i + 1, size - 1);
			counter++;
			
			return true;
		}
	}
	
	reverse(0, size - 1);
	counter = 0;
	
	return false;
}

bool Permutation::previous_permutation() {
	for(int i = size - 2; 0 <= i; i--) {
		if(a[i] > a[i + 1]) {
			int j = size - 1;
			while(a[i] < a[j]) { j--; }
			swap(i, j);
			reverse(i + 1, size - 1);
			counter--;
			
			return true;
		}
	}
	
	reverse(0, size - 1);
	counter = frac(size) - 1;
	
	return false;
}


int n, m;
bool e[8][8];

int main() {
	cin >> n >> m;
	inc(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a][b] = true;
		e[b][a] = true;
	}
	
	int ans = 0;
	
	Permutation p(n);
	do {
		bool flag = (p.get_at(0) == 0);
		inc(i, n - 1) {
			flag &= e[ p.get_at(i) ][ p.get_at(i + 1) ];
		}
		if(flag) { ans++; }
	} while(p.next_permutation());
	
	cout << ans << endl;
	
	return 0;
}
