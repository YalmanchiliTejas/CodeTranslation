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

const ULL mod = 1e9 + 7;				//常用模数(可根据题目需要修改)
const ULL inf = 0x7fffffff;				//用来表示无限大
const ULL infLL = 0x7fffffffffffffffLL;	//用来表示无限大
/*-------------------Define End-------------------*/

const UDW maxN = 1e6 + 7;
string N;
SLL len;
SDW K;
SLL ans;

void input(){
	cin >> N >> K;
	len = N.size();
}

void do1() {
	SDW a = N[0] - '0';
	SLL posA = len; // 从1开始从右往左数a在第几个 
	
	// 1 ~ len - 1位数的情况 
	ans += 9 * (posA - 1); 
	// len位数的情况 
	ans += a;
}

void do2() {
	SDW a = N[0] - '0';
	SLL posA = len; // 从1开始从右往左数a在第几个 
	
	SDW b = 0; // b为从左往右数第二个非零的数，不存在就置为0，然后位置设为1 
	SLL posB = 1;
	
	For(i, 1, len - 1) {
		if(N[i] != '0') {
			b = N[i] - '0';
			posB = len - i;
			break;
		}
	}
	
	// 1 ~ len - 1位数的情况 
	ans += 9 * (posA - 1) * (posA - 2) * 9 / 2; 
	// len位数的情况 
	ans += (a - 1) * (posA - 1) * 9;			// posA上置 1 ~ a-1 
	ans += (posB - 1) * 9;						// posA上置 a, posB上置 0 
	ans += b;									// posA上置 a, posB上置 1 ~ b 
}

void do3() {
	SDW a = N[0] - '0';
	SLL posA = len; // 从1开始从右往左数a在第几个 
	
	SDW b = 0; // b为从左往右数第二个非零的数，不存在就置为0，然后位置设为1 
	SLL posB = 1;
	
	For(i, 1, len - 1) {
		if(N[i] != '0') {
			b = N[i] - '0';
			posB = len - i;
			break;
		}
	}
	
	SDW c = 0; // c为从左往右数第三个非零的数，不存在就置为0，然后位置设为1 
	SLL posC = 1;
	
	For(i, len - posB + 1, len - 1) {
		if(N[i] != '0') {
			c = N[i] - '0';
			posC = len - i;
			break;
		}
	}
	
	// 1 ~ len - 1位数的情况 (朱世杰恒等式)
	ans += 9 * 9 * 9 * (posA - 1) * (posA - 2) * (posA - 3) / 6;
	// len位数的情况 
	ans += (a - 1) * 9 * 9 * (posA - 1) * (posA - 2) / 2; 	// posA上置 1 ~ a-1 
	ans += 9 * 9 * (posB - 1) * (posB - 2) / 2; 			// posA上置a, posB上置 0 
	ans += (b - 1) * (posB - 1) * 9; 						// posA上置a, posB上置 1 ~ b-1 
	ans += (posC - 1) * 9;									// posA上置a, posB上置 b, posC上置0 
	ans += c;												// posA上置a, posB上置 b, posC上置1~c 
}

void solve(){
	switch(K) {
		case 1:{
			do1();
			break;
		}
		case 2:{
			do2();
			break;
		}
		case 3:{
			do3();
			break;
		}
		default:{
			assert(false);
		}
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