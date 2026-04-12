#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    for(int n; scanf("%d", &n),n;) {
        int sum=0,miv=1000,mav=0;
        for(int i = 0; i < n; i++) {
            int s; scanf("%d", &s);
            sum+=s;
            miv=min(miv,s);
            mav=max(mav,s);
        }
        printf("%d\n", (sum-miv-mav)/(n-2));
    }
    return 0;
}