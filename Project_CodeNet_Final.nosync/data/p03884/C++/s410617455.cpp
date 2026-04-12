#include <cstdio>
#include <string>
using namespace std;

long long n;
string res;

long long getVal(int x) {
    long long ans = 1;

    for(int i = x, j = 2; i <= x + 6; ++i) {
        ans *= i;

        for(; j <= 7 && ans % j == 0; ++j)
            ans /= j;
    }

    return ans;
}

int main() {

    scanf("%lld", &n);

    for(int i = 600; i >= 1; --i) {
        long long x = getVal(i);
        int cntF = n / x;
        n %= x;

        if(cntF > 0)
            res += string(cntF, 'F');
        res += string("ESTIVAL");
    }

    printf("%s\n", res.c_str());

    return 0;
}