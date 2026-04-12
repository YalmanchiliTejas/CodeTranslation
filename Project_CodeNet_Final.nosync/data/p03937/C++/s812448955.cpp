#include <bits/stdc++.h>
using namespace std;

// Macro Tools /////////////////////////////////////////////////////////////////
#define GET_MACRO_09(A0, A1, A2, A3, A4, A5, A6, A7, A8, NAME, ...) NAME

#define EXPAND_01(MACRO, A0, ...) \
	MACRO(A0, ##__VA_ARGS__) 
#define EXPAND_02(MACRO, A0, A1, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) 
#define EXPAND_03(MACRO, A0, A1, A2, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__) 
#define EXPAND_04(MACRO, A0, A1, A2, A3, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__)  \
	MACRO(A3, ##__VA_ARGS__) 
#define EXPAND_05(MACRO, A0, A1, A2, A3, A4, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__)  \
	MACRO(A3, ##__VA_ARGS__) MACRO(A4, ##__VA_ARGS__) 
#define EXPAND_06(MACRO, A0, A1, A2, A3, A4, A5, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__)  \
	MACRO(A3, ##__VA_ARGS__) MACRO(A4, ##__VA_ARGS__) MACRO(A5, ##__VA_ARGS__) 
#define EXPAND_07(MACRO, A0, A1, A2, A3, A4, A5, A6, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__)  \
	MACRO(A3, ##__VA_ARGS__) MACRO(A4, ##__VA_ARGS__) MACRO(A5, ##__VA_ARGS__)  \
	MACRO(A6, ##__VA_ARGS__) 
#define EXPAND_08(MACRO, A0, A1, A2, A3, A4, A5, A6, A7, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__)  \
	MACRO(A3, ##__VA_ARGS__) MACRO(A4, ##__VA_ARGS__) MACRO(A5, ##__VA_ARGS__)  \
	MACRO(A6, ##__VA_ARGS__) MACRO(A7, ##__VA_ARGS__) 
#define EXPAND_09(MACRO, A0, A1, A2, A3, A4, A5, A6, A7, A8, ...) \
	MACRO(A0, ##__VA_ARGS__) MACRO(A1, ##__VA_ARGS__) MACRO(A2, ##__VA_ARGS__)  \
	MACRO(A3, ##__VA_ARGS__) MACRO(A4, ##__VA_ARGS__) MACRO(A5, ##__VA_ARGS__)  \
	MACRO(A6, ##__VA_ARGS__) MACRO(A7, ##__VA_ARGS__) MACRO(A8, ##__VA_ARGS__) 

#define GET_EXPAND(...) GET_MACRO_09(__VA_ARGS__, EXPAND_09, EXPAND_08, \
	EXPAND_07, EXPAND_06, EXPAND_05, EXPAND_04, EXPAND_03, EXPAND_02, EXPAND_01)
#define EXPAND_ARG_0(MACRO, ...) GET_EXPAND(__VA_ARGS__)(MACRO, __VA_ARGS__)
#define EXPAND_ARG_1(MACRO, A0, ...) GET_EXPAND(__VA_ARGS__)(MACRO, __VA_ARGS__, A0)

#define EXPAND(MACRO, ...) EXPAND_ARG_0(MACRO, __VA_ARGS__)

#define Q(x) #x
#define QUOTE(x) Q(x)

// Input ///////////////////////////////////////////////////////////////////////
#define SCANF_INT(a) scanf("%d", &(a));
#define ID(...) int __VA_ARGS__;
#define IR(...) {EXPAND(SCANF_INT, __VA_ARGS__)}
#define I(...) ID(__VA_ARGS__) IR(__VA_ARGS__)

// #define DEFINE_INT_ARRAY(a, n) int a[n];
// #define INT_ITH_ARRAY(a, i) a[i]
// #define IAD(N, ...) EXPAND_ARG_1(DEFINE_INT_ARRAY, N, __VA_ARGS__)
// #define IAR(N, ...) REP(array_reader_i, N){ 

#define SCANF_LL(a) scanf("%lld", &(a));
#define LD(...) ll __VA_ARGS__;
#define LR(...) {EXPAND(SCANF_LL, __VA_ARGS__)}
#define L(...) LD(__VA_ARGS__) LR(__VA_ARGS__)

#define SCANF_LD(a) scanf("%Lf", &(a));
#define DD(...) lD __VA_ARGS__;
#define DR(...) {EXPAND(SCANF_LD, __VA_ARGS__)}
#define D(...) DD(__VA_ARGS__) DR(__VA_ARGS__)

#define DEFINE_STR(a, n) char a[n];
#define SCANF_STR(a) scanf("%s", a);
#define SD(N, ...) EXPAND_ARG_1(DEFINE_STR, N, __VA_ARGS__)
#define SR(...) EXPAND(SCANF_STR, __VA_ARGS__)
#define S(N, ...) SD(N, __VA_ARGS__) SR(__VA_ARGS__)

// Output //////////////////////////////////////////////////////////////////////
#define LN printf("\n");

#define IP(a, ...) printf("%d", a); 

// Types ///////////////////////////////////////////////////////////////////////
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef list<int> li;
typedef list<ll> lll;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, int> mli;
typedef map<ll, ll> mll;

// Loop & Iteration ////////////////////////////////////////////////////////////
#define FORT(t, i, a, b) \
	for(t i = (a), loop_end_##i=(b); i < (loop_end_##i); i++)
#define FORL(i, a, b) FORT(ll, i, a, b)
#define FOR(i, a, b) FORT(int, i, a, b)
#define REPT(t, i, n) FORT(t, i, 0, n)
#define REPL(i, n) FORL(i, 0, n)
#define REP(i, n) FOR(i, 0, n)
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)

#define EXIST(s,e) ((s).find(e)!=(s).end())
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define SORTA(a, n) sort(a, a+n)

#define PB push_back
#define MP make_pair
#define itr iterator

// Range ///////////////////////////////////////////////////////////////////////
#define IN(x, a, b) (a<=x && x<b)
#define INC(x, a, b) (a<=x && x<=b)
int dx[8] = { 1, 0, 0,-1, 1, 1,-1,-1};
int dy[8] = { 0,-1, 1, 0,-1, 1,-1, 1};

#define LAR(a, b) ((a)=max((a), (b)))
#define SML(a, b) ((a)=min((a), (b)))

// Debug ///////////////////////////////////////////////////////////////////////
#define println(...) {printf(__VA_ARGS__); printf("\n");}
#ifdef LOCAL
#define debug(...) printf(__VA_ARGS__)
#define debugln(...) println(__VA_ARGS__)
#else
#define debug(...) {}
#define debugln(...) {}
#endif

// Numbers /////////////////////////////////////////////////////////////////////
ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

#define PRIME_MAX 1000000
bool isprime[PRIME_MAX+5];
void init_prime(){
	fill(isprime, isprime+PRIME_MAX+5, true);
	isprime[0]=isprime[1]=false;
	REP(i, PRIME_MAX+5){
		if(isprime[i]){
			for(int j=i*2; j<PRIME_MAX; j+=i){
				isprime[j]=false;
			}
		}
	}
}

vll factors(ll n){
	vll v;
	REPL(i, PRIME_MAX){
		if(!isprime[i]) continue;
		while(n%i==0){
			v.PB(i);
			n/=i;
		}
	}
	if(n>1){
		v.PB(n);
	}
	return v;
}

// BIT /////////////////////////////////////////////////////////////////////////
template<
	typename T = int
>
class bit{
public:
	T *bit_arr;
	int size;

	bit(int n){
		size = n;
		bit_arr = new T[n];
		fill(bit_arr, bit_arr+n, 0);
	}

	~bit(){
		delete bit_arr;
	}

	T sum(int a){
		T ret = 0;
		while(a){
			ret+=bit_arr[a];
			a-=a&-a;
		}
		return ret;
	}

	T sum(int a, int b){
		return sum(b)-sum(a);
	}

	T get(int a){
		return sum(a, a+1);
	}

	void add(int a, T x){
		a++;
		while(a<size){
			bit_arr[a]+=x;
			a+=a&-a;
		}
	}

	void set(int a, T x){
		add(a, x-get(a));
	}
};
typedef bit<ll> bll;

// RMQ /////////////////////////////////////////////////////////////////////////
template<
	typename T = int,
	class Compare=less<T>
>
class rmq{
public:
	int size;
	Compare comp;
	T *dat;
	T init;
	
	rmq(int n, T init_=INT_MAX){
		init=init_;
		size = 1;
		while(size<n) size*=2;
		dat = new T[2*size-1];
		fill(dat, dat+(2*size-1), init);
	}

	~rmq(){
		delete dat;
	}

	void set(int k, T a){
		k+=size-1;
		dat[k]=a;
		while(k>0){
			k=(k-1)/2;
			dat[k]=min(dat[k*2+1], dat[k*2+2], comp);
		}
	}

	T get(int a, int b, int k, int l, int r){
		if(r<=a || b<=l) return init;
		if(a<=l && r<=b) return dat[k];
		else{
			T vl = get(a, b, k*2+1, l, (l+r)/2);
			T vr = get(a, b, k*2+2, (l+r)/2, r);
			return min(vl, vr, comp);
		}
	}

	T get(int a, int b){
		return get(a, b, 0, 0, size);
	}
};

// Others //////////////////////////////////////////////////////////////////////
#define MOD 1000000007
#define YES() printf("YES\n")
#define NO() printf("NO\n")

////////////////////////////////////////////////////////////////////////////////

char s[10][10];
int a[10], b[10];

int main(){
	I(h, w);
	REP(i, h) scanf("%s", s[i]);
	bool ok = true;
	REP(i, h){
		int x=0;
		while(x<w && s[i][x]=='.') x++;
		a[i]=x;
		while(x<w && s[i][x]=='#') x++;
		b[i]=x;
		while(x<w && s[i][x]=='.') x++;
		if(x<w) ok=false;
	}
	FOR(i, 1, h){
		if(b[i-1]-1!=a[i]){
			ok = false;
			break;
		}
	}
	if(ok) printf("Possible\n");
	else printf("Impossible\n");
}


