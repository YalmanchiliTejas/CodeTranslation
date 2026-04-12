#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;
long long max (long long a, long long b) {if (a > b) return a; return b;}
 
int main()
{
    int N;
    int a[200005] = {0};
    long long dp4[200005][3] = {0};
    long long sum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    long long ans = LLONG_MIN;
        dp4[0][0] = a[0]; dp4[0][1] = INT_MIN;  dp4[0][2] = INT_MIN;
        dp4[1][1] = a[1]; 
        dp4[1][2] = INT_MIN; 
        dp4[1][0] = INT_MIN; 
        dp4[2][2] = a[2]; 
        for (int i = 2; i < N; i++) {
            dp4[i][0] = dp4[i-2][0] + a[i];
            dp4[i][1] = dp4[i-2][1]+a[i];
            if (i - 3 >= 0) dp4[i][1] = max(dp4[i][1], dp4[i-3][0] + a[i]); 
            else dp4[i][1] = max(dp4[i][1], a[i]);
            dp4[i][2] = dp4[i-2][2]+a[i];
            if (i - 3 >= 0) dp4[i][2] = max(dp4[i][2], dp4[i-3][1] + a[i]); 
            if (i - 4 >= 0) dp4[i][2] = max(dp4[i][2], dp4[i-4][0] + a[i]); 
            else dp4[i][2] = max(dp4[i][2], a[i]);
        }
        if (N % 2 == 0){
            if (N - 1 >= 0)ans = max(ans, dp4[N-1][1]);
            if (N - 2 >= 0)ans = max(ans, dp4[N-2][0]);
        }else {
            if (N - 1 >= 0)ans = max(ans, dp4[N-1][2]);
            if (N - 2 >= 0)ans = max(ans, dp4[N-2][1]);
            if (N - 3 >= 0)ans = max(ans, dp4[N-3][0]);
        }
        cout << ans << endl;
    return 0;
}
