#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<ctime>
#define eps 1e-6
#define LL long long
#define pii (pair<int, int>)
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int maxn = 20000 + 100;
//const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int n;
LL po[maxn];
void init_po() {
    po[0] = 1;
    for(int i = 1; i <= 10000+1000; i++) {
        po[i] = po[i-1]*10;
        if(po[i] >= mod) po[i] %= mod;
    }
}
LL pre[maxn], post[maxn];
void init(char* str) {
    int len = strlen(str);
    pre[0] = str[0] - '0';
    for(int i = 1; i < len; i++) {
        pre[i] = pre[i-1]*10 + str[i] - '0';
        if(pre[i] >= mod) pre[i] %= mod;
    }
    post[len-1] = str[len-1] - '0';
    for(int i = len-2; i >= 0; i--) {
        post[i] = (str[i]-'0')*po[len-i-1]+post[i+1];
        post[i] %= mod;
    }
}

LL solve(char* str, char* tar) {
    init(str);
    int lens = strlen(str), lent = strlen(tar);
    LL ans = 0;
    if(tar[0] == '0') {
        ans = (ans+pre[lens-lent-1]) % mod;
        //cout << ans << endl;
        //cout << pre[0] << endl;
        for(int i = 1; i+lent < lens; i++) {
            int tmp = strncmp(str+i, tar, lent);
            if(tmp > 0) ans = (ans + (pre[i-1])*(po[lens-i-lent])) % mod;
            else if(!tmp) ans = (ans + (pre[i-1]-1)*(po[lens-i-lent])+(post[i+lent]+1)) % mod;
        }
        return ans;
    }
    if(lens < lent) return 0;
    if(lens == lent) return strncmp(str, tar, lens)>=0 ? 1:0;
    if(tar[0]!='0' && strncmp(str, tar, lent) == 0) ans += post[lent]+1;
    else if(tar[0]!='0' && strncmp(str, tar, lent) > 0) ans += po[lens-lent];
    //cout << post[len-1] << endl;
    //cout << ans << endl;
    if(strncmp(str+lens-lent, tar, lent) >= 0) ans = (ans+pre[lens-lent-1]+1) % mod;
    else ans = (ans+pre[lens-lent-1]) % mod;
    //cout << ans << endl;
    //cout << pre[0] << endl;
    for(int i = 1; i+lent < lens; i++) {
        int tmp = strncmp(str+i, tar, lent);
        if(tmp > 0) ans = (ans + (pre[i-1]+1)*(po[lens-i-lent])) % mod;
        else if(!tmp) ans = (ans + (pre[i-1])*(po[lens-i-lent])+(post[i+lent]+1)) % mod;
        else ans = (ans + (pre[i-1])*(po[lens-i-lent])) % mod;
    }
    //cout << ans << endl;
    return ans;
}
char sl[maxn], sr[maxn], tar[maxn];

int f[maxn];

void getFail() {
	int m = strlen(tar);
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < m; i++) {
		int j = f[i];
		while(j && tar[i]!=tar[j]) j = f[j];
		f[i+1] = tar[i]==tar[j] ? j+1 : 0;
	}
}

int find_p() {
	int ans = 0;
	int n = strlen(sl), m = strlen(tar);
	getFail();
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j && tar[j]!=sl[i]) j = f[j];
		if(tar[j] == sl[i]) j++;
		if(j == m) ans++, j=f[j];
	}
	return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    init_po();
    while(scanf("%s%s", sl, sr) == 2) {
        scanf("%s", tar);
        LL ans = 0;
        ans = solve(sr, tar)-solve(sl, tar);
        //cout << solve(sr, tar) << endl;
        //solve(sr, tar);
        getFail();
        ans = ((ans+find_p())%mod+mod) % mod;
        cout << ans << endl;
    }
    return 0;
}