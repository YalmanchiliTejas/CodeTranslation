//h17-4
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define segment_size 65536
#define ROOP() while (true)

int main(){
    int N;
    cin >> N;
    int t[100000];
    int m = 0;
    for(int i=0; i<N; i++){
        cin >> t[i];
        m = max(m, t[i]);
    }

    set<int> yakusu;
    for(int i=1; i<=m; i++){
        if(m % i == 0) yakusu.insert(i);
    }
    LL ans = 0;
    for(int i=0; i<N; i++){
        ans += *(yakusu.lower_bound(t[i])) - t[i];
    }

    cout << ans << endl;

    return 0;
}
