#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
long long N;
const long long MAX_NUM = 1e5;
long long Pri[100001];
long long L[100001];
long long a[1005];
long long ans;
map<long long, long long> M;
void check(long long T) {
    long long temp = 0;
    for(long long i = 1; i <= N; i++)
        if(a[i] % T == 0)
            temp += a[i];
    ans = max(temp, ans);
}
void  resolve(long long n) {
    if(n == 1)
        return ;
    for (long long i = 1; i <= L[0]; i++)
        if (n % L[i] == 0) {
            if(M[L[i]] >= 0)
                check(L[i]);
            while(n % L[i] == 0 && n > 1)
                n /= L[i];
        }
    if(n != 1)
        check(n);
}
int main() {
	for (long long i = 2; i <= MAX_NUM; i++)
		Pri[i] = 1;
	for (long long i = 2; i <= MAX_NUM; i++) {
		if (Pri[i])
			for (long long j = 2 * i; j <= MAX_NUM; j += i)
				Pri[j] = 0;
	}
	for (long long i = 2; i <= MAX_NUM; i++)
		if (Pri[i])
			L[++L[0]] = i;
    cin >> N;
    for(long long i = 1; i <= N; i++)
        cin >> a[i];
    for(long long i = 1; i <= N; i++)
        resolve(a[i]);
    cout << ans << endl;
	return 0;
}


