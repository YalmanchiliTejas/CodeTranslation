#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

long long llpow(long long x, long long n) {
    long long ans = 1;
    if (n == 0)return 1;
    while (n != 0) {
        if (n & 1) ans = ans * x;
        x = x * x;
        n = n >> 1;
    }
    return ans;
}


int main() {
	long long N, X;
	cin >> N >> X;
    long long an = 8 * llpow(2, N - 1) - 3;
    
    long long countPutty = 0;
    while(1) {

        if (N == 1) {
            switch (X) {
            case 1:
                countPutty += 0;
                break;
            case 2:
                countPutty += 1;
                break;
            case 3:
                countPutty += 2;
                break;
            case 4:
                countPutty += 3;
                break;
            case 5:
                countPutty += 3;
                break;
            }
            break;
        }
        an = 8 * llpow(2, N - 1) - 3;
        --N;

        if ((an + 1) / 2 == X) {
            long long prean = 8 * llpow(2, N - 1) - 3;
            countPutty += (prean + 1) / 2 + 1;
            break;
        }
        else if (an == X) {
            countPutty += (an + 1) / 2;
            break;
        }
        else if ((an + 1) / 2 < X) {
            X -= (an + 1) / 2;
            long long prean = 8 * llpow(2, N - 1) - 3;
            countPutty += (prean + 1) / 2 + 1;
        }
        else {
            --X;
        }
    }

    cout << countPutty << endl;
	return 0;
}