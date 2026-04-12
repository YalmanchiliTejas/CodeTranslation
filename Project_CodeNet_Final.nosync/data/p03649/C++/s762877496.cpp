#include <bits/stdc++.h>
using namespace std;

ifstream in ("test.in" );
ofstream out("test.out");

const int DIM = 2e5 + 5;
const int INF = 0x3f3f3f3f;

long long arr[DIM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    
    long long ans = 0;
    while (true) {
        if (*max_element(arr + 1, arr + n + 1) < n)
            break;
    
        long long cnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j)
                    continue;
                
                arr[j] += arr[i] / n;
            }
            
            ans += arr[i] / n; arr[i] %= n;
        }
    }
    
    cout << ans << endl;
    return 0;
}
