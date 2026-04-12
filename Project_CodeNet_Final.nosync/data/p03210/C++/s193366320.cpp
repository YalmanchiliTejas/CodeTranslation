#include <bits/stdc++.h>

using namespace std;

#define countof(a) (sizeof(a)/sizeof(*a))

#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pi >
#define pi pair<int,int>
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

/* ------------------------ */
/* BEGIN EXTERNAL LIBRARIES */
/* ------------------------ */

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
    operator int() const { return x; }                           // added by QCFium
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

struct UnionFind{
    vi data;
    UnionFind(int size):data(size,-1){}
    bool unite(int x,int y) {
        x=root(x);y=root(y);
        if(x!=y){
            if(data[y]<data[x])swap(x,y);
            data[x]+=data[y];data[y]=x;
        }
        return x!=y;
    }
    bool find(int x,int y) {
        return root(x)==root(y);
    }
    int root(int x) {
        return data[x]<0?x:data[x]=root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
    // added by QCFium
    bool united() {
        int comroot = -1;
        FOR(i,data.size()) {
            if (comroot != -1 && root(i) != comroot) return false;
            comroot = root(i);
        }
        return true;
    }
};

/* ---------------------- */
/* END EXTERNAL LIBRARIES */
/* ---------------------- */

int mpow(s64 num, s64 times) { // O(log(times))
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

struct MComb {
    vector<mint> fact;
    vector<mint> inversed;
    MComb(int n) { // O(n+log(mod))
        fact = vector<mint>(n+1,1);
        UPTO(i,1,n) fact[i] = fact[i-1]*mint(i);
        inversed = vector<mint>(n+1);
        inversed[n] = mpow(fact[n], MOD-2);
        DOWN(i,n) inversed[i]=inversed[i+1]*mint(i+1);
    }
    
    int ncr(int n, int r) {
        return fact[n] * inversed[r] * inversed[n-r];
    }
    
    int npr(int n, int r) {
        return fact[n] * inversed[n-r];
    }
    
    int nhr(int n, int r) {
        assert(n+r-1 < (int)fact.size());
        return ncr(n+r-1, r);
    }
};

template<class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
set<Key> operator+(set<Key>& a, set<Key>& b) {
    set<Key> c = a;
    for (auto i : b) 
        c.insert(i);
    return c;
}
template<class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
set<Key> operator+=(set<Key>& a, set<Key>& b) {
    for (auto& i : b)
        a.insert(i);
    return a;
}

template<class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
set<Key> operator*(set<Key>& a, set<Key>& b) {
    set<Key> c;
    for (auto& i : a)
        if (b.count(i)) c.insert(i);
    return c;
}
template<class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
set<Key> operator*=(set<Key>& a, set<Key>& b) {
    set<Key> c;
    for (auto& i : a)
        if (b.count(i)) c.insert(i);
        
    return a = c;
}

template<class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
set<Key> operator-(set<Key>& a, set<Key>& b) {
    set<Key> c;
    for (auto& i : a)
        if (!b.count(i)) c.insert(i);
        
    return c;
}
template<class Key, class Compare = less<Key>, class Allocator = allocator<Key>>
set<Key> operator-=(set<Key>& a, set<Key>& b) {
    set<Key> c;
    for (auto& i : a)
        if (!b.count(i)) c.insert(i);
        
    return a = c;
}

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

int main() {
	int n = ri();
	puts(n == 5 || n == 7 || n == 3 ? "YES" : "NO");
    return 0;
}
