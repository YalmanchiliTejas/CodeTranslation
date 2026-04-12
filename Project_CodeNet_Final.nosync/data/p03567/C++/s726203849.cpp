

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for ( int i=1; i<=int(n); i++ )  
#define MP make_pair
#define PB push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define X first
#define Y second
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;
typedef pair<int, int> pii;
typedef long double LD;
const int INF = 0x3f3f3f3f;

template <class T>  
inline bool RD(T &ret) {  
        char c; int sgn;  
		if (c = getchar(), c == EOF) return 0;  
        while (c != '-' && (c<'0' || c>'9')) c = getchar();  
        sgn = (c == '-') ? -1 : 1 , ret = (c == '-') ? 0 : (c - '0');  
        while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');  
        ret *= sgn;  
        return 1;  
}  
template <class T>  
inline void PT(T x) {  
        if (x < 0) putchar('-') ,x = -x;  
        if (x > 9) PT(x / 10);  
        putchar(x % 10 + '0');  
}


int main() {
    string s;
    cin >> s;
    for(int i =  0; i < SZ(s); i ++) 
        if(s[i] == 'A' && i + 1 < SZ(s) && s[i + 1] == 'C') {
            return puts("Yes"), 0;
        }
    puts("No");
}
