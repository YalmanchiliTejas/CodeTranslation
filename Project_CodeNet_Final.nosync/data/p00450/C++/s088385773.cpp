#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    while(true) {
        int n; scanf("%d", &n);
        if(n==0) break;
        static int stk[100010];
        int stk_siz = 0;
        for(int i = 0; i < n; i++) {
            if(stk_siz == 0) {
                stk[stk_siz++] = 0;
                stk[stk_siz++] = 0;
            }
            int x; scanf("%d", &x);
            if(x ^ (stk_siz & 1)) {
                if(i & 1)
                    stk_siz--;
                else
                    stk[stk_siz++] = i;
            }
        }
        stk[stk_siz++] = n;
        stk[stk_siz++] = n;
        int c=0;
        for(int i = 0; i+2 <= stk_siz; i+=2) {
            c += stk[i+1] - stk[i];
        }
        printf("%d\n", n-c);
    }
    return 0;
}