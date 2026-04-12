#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define countof(a) (sizeof(a)/sizeof(*a))

#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pi >
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define all(n) n.begin(), n.end()

#define FROMTO(var, from, to) for (register int var = (from), var##down = ((int)(to)) < ((int)(from));var##down ? (var >= (int)(to)) : (var <= (int)(to));var##down ? var-- : var++)
#define UPTO(var, from, to)   for (register int var = (from); var <= ((int)to); var++)
#define DOWNTO(var, from, to) for (register int var = (from); var >= ((int)to); var--)
#define FOR(var, to)          UPTO(var, 0, (to)-1)
#define DOWN(var, from)       DOWNTO(var, (from)-1, 0)

#define INIT(var, val) FOR(i,countof(var)) var[i] = val
#define INPUT(var) FOR(i,countof(var)) cin >> var[i]
#define INPUT1(var) FOR(i,countof(var)) cin >> var[i], var[i]--

#define SORT(v) qsort(v,countof(v),sizeof(*v),int_less)
#define SORTT(v) qsort(v,countof(v),sizeof(*v),int_greater)
#define QSORT(v,b) qsort(v,countof(v),sizeof(*v),b)

#define MOD 1000000007
#define INF ((1 << 30)-1)
#define LINF ((1LL << 62)-1)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

struct Comb {
    vector<vector<s64> > data;
    Comb(int n) { // O(n^2)
        data = vector<vector<s64> >(n+1,vector<s64>(n+1,1));
        UPTO(i,1,n) {
            FOR(j,i+1) {
                if (!j || j == i) data[i][j] = 1;
                else data[i][j] = data[i-1][j-1] + data[i-1][j];
            }
        }
    }

    s64 ncr(int n, int r) {
        return data[n][r];
    }
};

static inline int ri() {
  int a;
  scanf("%d", &a);
  return a;
}

int int_less(const void *a, const void *b) {
  return (*((const int*)a) - *((const int*)b));
}
int int_greater(const void *a, const void *b) {
  return (*((const int*)b) - *((const int*)a));
}

template<int mod>
struct ModInt{
    int x;
    ModInt():x(0){}
    ModInt(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}
    ModInt &operator+=(const ModInt &p){
        if((x+=p.x)>=mod)x-=mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if((x+=mod-p.x)>=mod)x-=mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x=(int)(1LL*x*p.x%mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
        *this*=p.inverse();
        return *this;
    }
    ModInt operator-()const{return ModInt(-x);}
    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
    bool operator==(const ModInt &p)const{return x==p.x;}
    bool operator!=(const ModInt &p)const{return x!=p.x;}
    explicit operator int() const { return x; }                           // added by QCFium
    ModInt operator=(const int p) {x = p; return ModInt(*this);} // added by QCFium
    ModInt inverse()const{
        int a=x,b=mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            a-=t*b;
            swap(a,b);
            u-=t*v;
            swap(u,v);
        }
        return ModInt(u);
    }
    friend ostream &operator<<(ostream &os,const ModInt<mod> &p){
        return os<<p.x;
    }
    friend istream &operator>>(istream &is,ModInt<mod> &a){
        long long x;
        is>>x;
        a=ModInt<mod>(x);
        return (is);
    }
};
typedef ModInt<MOD> mint;

mint mpow(s64 num, s64 times) { // O(log(times))
    mint next = num%MOD;
	mint res = 1;
	while (times) {
		if (times%2)
            res *= next;
		next *= next;
		times /= 2;
	}
	return res;
}

struct MComb {
    vector<mint> fact;
    vector<mint> inversed;
    MComb(int n) { // O(n+log(mod))
        fact = vector<mint>(n+1,1);
        UPTO(i,1,n) fact[i] = fact[i-1]*mint(i);
        inversed = vector<mint>(n+1);
        inversed[n] = mpow((int)fact[n], MOD-2);
        DOWN(i,n) inversed[i]=inversed[i+1]*mint(i+1);
    }

    mint ncr(int n, int r) {
        return (fact[n] * inversed[r] * inversed[n-r]);
    }

    mint npr(int n, int r) {
        return (fact[n] * inversed[n-r]);
    }

    mint nhr(int n, int r) {
        assert(n+r-1 < (int)fact.size());
        return ncr(n+r-1, r);
    }
};


int main() {
    int n = ri();
	int m = ri();
	int s = ri()-1;
	int t = ri()-1;
	int a[m], b[m], c[m];
	vector<pair<int,int> > hen[n];
	FOR(i,m) {
		a[i] = ri()-1;
		b[i] = ri()-1;
		c[i] = ri();
		hen[a[i]].push_back({b[i], c[i]});
		hen[b[i]].push_back({a[i], c[i]});
	}
	using T = pair<s64,int>;
	s64 dist1[n];
	mint num1[n];
	INIT(dist1, LINF);
	INIT(num1, 0);
	dist1[s] = 0;
	num1[s] = 1;
	priority_queue<T, vector<T>, greater<T> > que;
	que.push({0,s});
	while (que.size()) {
		auto i = que.top(); que.pop();
		if (dist1[i.se] != i.fi) continue;
		for (auto j : hen[i.se]) {
			if (dist1[j.fi] > dist1[i.se] + j.se) {
				dist1[j.fi] = dist1[i.se] + j.se;
				num1[j.fi] = num1[i.se];
				que.push({dist1[j.fi],j.fi});
			} else if (dist1[j.fi] == dist1[i.se] + j.se) {
				num1[j.fi] += num1[i.se];
			}
		}
	}

	s64 dist2[n];
	mint num2[n];
	INIT(dist2, LINF);
	INIT(num2, 0);
	dist2[t] = 0;
	num2[t] = 1;
	que.push({0,t});
	while (que.size()) {
		auto i = que.top(); que.pop();
		if (dist2[i.se] != i.fi) continue;
		for (auto j : hen[i.se]) {
			if (dist2[j.fi] > dist2[i.se] + j.se) {
				dist2[j.fi] = dist2[i.se] + j.se;
				num2[j.fi] = num2[i.se];
				que.push({dist2[j.fi], j.fi});
			} else if (dist2[j.fi] == dist2[i.se] + j.se) {
				num2[j.fi] += num2[i.se];
			}
		}
	}

	assert(dist1[t] == dist2[s]);
	mint res = num1[t] * num2[s];
	FOR(i,n) {
		// v
		if (dist1[i] == dist2[i] && dist1[i] + dist2[i] == dist1[t]) {
			res -= num1[i] * num2[i] * num1[i] * num2[i];
		}
	}
	FOR(i,m) {
		// e
		if (dist1[a[i]] + dist2[b[i]] + c[i] == dist1[t]) {
			assert(dist1[a[i]] + c[i] == dist1[b[i]]);
			assert(dist2[b[i]] + c[i] == dist2[a[i]]);
			if (dist1[b[i]] > dist2[b[i]] &&
				dist1[a[i]] < dist2[a[i]]) {
				res -= num1[a[i]] * num1[a[i]] * num2[b[i]] * num2[b[i]];
			}
		} else if (dist1[b[i]] + dist2[a[i]] + c[i] == dist1[t]) {
			assert(dist1[b[i]] + c[i] == dist1[a[i]]);
			assert(dist2[a[i]] + c[i] == dist2[b[i]]);
			if (dist1[a[i]] > dist2[a[i]] &&
				dist1[b[i]] < dist2[b[i]]) {
				res -= num1[b[i]] * num1[b[i]] * num2[a[i]] * num2[a[i]];
			}
		}
	}

	cout << res << endl;

    return 0;
}
