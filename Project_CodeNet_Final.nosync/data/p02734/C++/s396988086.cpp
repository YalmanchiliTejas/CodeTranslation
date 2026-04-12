#include <bits/stdc++.h>
using namespace std;

/*-------------------Define Start-------------------*/
typedef bool BL;    					// 布尔类型
typedef char SB;    					// 有符号1字节,8位
typedef unsigned char UB;    			// 无符号1字节,8位
typedef short SW;    					// 有符号短整型,16位
typedef unsigned short UW;    			// 无符号短整型,16位
typedef long SDW;    					// 有符号整型,32位
typedef unsigned long UDW;   			// 无符号整型,32位
typedef long long SLL;    				// 有符号长整型,64位
typedef unsigned long long ULL;			// 无符号长整型,64位
typedef char CH;    					// 单个字符
typedef float R32;    					// 单精度浮点数
typedef double R64;    					// 双精度浮点数

#define Rep(i, n) for (register SDW i = 0; i < (n); ++i)
#define For(i, s, t) for (register SDW i = (s); i <= (t); ++i)
#define rFor(i, t, s) for (register SDW i = (t); i >= (s); --i)
#define foreach(i, c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)
#define ms0(a) memset(a,0,sizeof(a))
#define msI(a) memset(a,0x7f,sizeof(a))
#define LOWBIT(x) ((x)&(-x))

#define MP make_pair
#define PB push_back
#define ft first
#define sd second

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

const ULL mod = 998244353;				//常用模数(可根据题目需要修改)
const ULL inf = 0x7fffffff;				//用来表示无限大
const ULL infLL = 0x7fffffffffffffffLL;	//用来表示无限大
/*-------------------Define End-------------------*/

const UDW maxN = 3e3 + 7;
SDW N, S;
SDW A[maxN];
SLL dp[maxN]; // dp[i][j] 表示当 R == i 时,和为 j 的序列个数 
SLL ans;

// Calculate x^y % p
inline SLL pow_mod(SLL x, SLL y, ULL p = mod){
    SLL ret = 1;
    while(y){
        if(y & 1) {
            ret = (ret * x) % p;
        }
        x = (x * x) % p;
        y >>= 1;
    }
    return ret;
} 

void input(){
	cin >> N >> S;
	For(i, 1, N) {
		cin >> A[i];
	}
}

void solve(){
	For(i, 1, N) {
		rFor(j, S, A[i]) {
			// 更新,不选和选两种情况 
			dp[j] = (dp[j] + dp[j - A[i]]) % mod;
		}
		if(A[i] <= S) {
			dp[A[i]] = (dp[A[i]] + i) % mod; // j == A[i]的情况需要特殊讨论 
		}
		ans = (ans + dp[S]) % mod;
	}
}

void output(){
	cout << ans << endl;
}

int main() {
	input();
	solve();
	output();
	return 0;
}
