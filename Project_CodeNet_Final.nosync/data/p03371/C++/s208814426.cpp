#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int c, A, B, C, x, y;
    long long answer=5000000000;
    cin >> A >> B >> C >> x >> y;

    for (c=0; c <= 100000; ++c) {
        long long money = c*2*C+max(0, x-c)*A+max(0, y-c)*B;
        answer = min(answer, money);
    }
    cout << answer << endl;
    return 0;
}
