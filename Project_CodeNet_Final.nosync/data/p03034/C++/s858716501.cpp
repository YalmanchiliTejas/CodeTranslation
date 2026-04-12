#include <bits/stdc++.h>

using namespace std;

const long long NS = (long long)1e5 + 4;
long long N;
long long arr[NS];
vector < long long > sum1[NS], sum2[NS];

int main(){
    scanf("%lld", &N);
    for(long long i = 1; i <= N; ++i) scanf("%lld", arr + i);
    for(long long i = 1; i <= N; ++i){
        long long pos = N - N / i * i, sum = 0;
        if(!pos) pos += i;
        while(pos <= N){
            sum += arr[pos]; sum1[i].push_back(sum);
            pos += i;
        }
        pos = 1, sum = 0;
        while(pos <= N){
            sum += arr[pos]; pos += i;
        }
        pos = 1;
        while(pos <= N){
            sum2[i].push_back(sum), sum -= arr[pos], pos += i;
        }
    }
    long long ans = -(long long)1e18;
    for(long long i = 1; i <= N; ++i){
        for(long long j = 1; i - j > 0 && j * j <= N - i; ++j){
            if((N - i - 1) % j == 0 && (i % j != 0 || i / j >= (N - i - 1) / j + 1)){
                long long A = i, B = i - j;
                long long gap1 = sum1[j][(long long)sum1[j].size() - 1];
                if((long long)sum1[j].size() - (N - A - 1) / j - 1){
                    gap1 -= sum1[j][(long long)sum1[j].size() - (N - A - 1) / j - 2];
                }
                long long gap2 = sum2[j][0];
                if((N - A - 1) / j + 1 < (long long)sum2[j].size()){
                    gap2 -= sum2[j][(N - A - 1) / j + 1];
                }
                ans = max(ans, gap1 + gap2);
            }
            if((N - i - 1) % j == 0 && (N - i - 1) / j != 0){
                long long jj = j; j = (N - i - 1) / j;
                if((N - i - 1) % j == 0 && (i % j != 0 || i / j >= (N - i - 1) / j + 1)){
                    long long A = i, B = i - j;
                    long long gap1 = sum1[j][(long long)sum1[j].size() - 1];
                    if((long long)sum1[j].size() - (N - A - 1) / j - 1){
                        gap1 -= sum1[j][(long long)sum1[j].size() - (N - A - 1) / j - 2];
                    }
                    long long gap2 = sum2[j][0];
                    if((N - A - 1) / j + 1 < (long long)sum2[j].size()){
                        gap2 -= sum2[j][(N - A - 1) / j + 1];
                    }
                    ans = max(ans, gap1 + gap2);
                }
                j = jj;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
