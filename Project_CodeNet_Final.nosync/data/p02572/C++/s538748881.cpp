#include <bits/stdc++.h>

#define gc() std::getchar()
#define pc(i) std::putchar(i)

template <typename T>
inline T read(){ 
	T x = 0;
	char ch = gc();
	bool f = 0;
	while(!std::isdigit(ch)){ 
		f = (ch == '-');
		ch = gc();
	} 
	while(std::isdigit(ch)){ 
		x = x * 10 + (ch - '0');
		ch = gc();
	} 
	return f ? -x : x; 
}

template <typename T>
void put(T x){ 
	if (x < 0){ 
		x = -x;
		pc('-');
	} 
	if (x < 10){ 
		pc(x + 48);
		return;
	} 
	put(x / 10);
	pc(x % 10 + 48);
	return ;
} 

#define For(i, j, k) for(int i = j; i <= k; ++i)
#define Rep(i, j, k) for(int i = j; i >= k; --i)
#define rdi() read <int> ()
#define rdl() read <long long> ()
#define pti(i) put <int> (i), putchar(' ')
#define ptl(i) put <long long> (i), putchar(' ')
#define pub(i) push_back(i)
#define pob() pop_back()

typedef long long ll;
typedef float fl;
typedef double db;

const int N = 2.2e5;
const int P = 1e9 + 7;
int a[N], s[N];

void fake_main(){ 
	int n = rdi();
	For(i, 1, n) a[i] = rdi();
	
	s[n] = a[n];
	Rep(i, n - 1, 2) s[i] = (a[i] + s[i + 1]) % P;
	
	int ans = 0;
	For(i, 2, n) ans = (1ll * a[i - 1] * s[i] + ans) % P;
	
	printf("%d\n", ans);
} 

int main(){ 
	fake_main();
	
	return 0;
} 