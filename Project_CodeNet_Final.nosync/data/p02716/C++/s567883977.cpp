#include <bits/stdc++.h>
using namespace std;
int N, A;
queue<long long> que;
int main () {
    que.push(0);
    que.push(0);
    scanf("%d%d", &N, &A);
    long long x = A;
    for (int i = 2; i <= N; i++) {
        scanf("%d", &A);
        if (i % 2 == 0) {
            que.push(max(que.front()+A, x));
        }
        else {
            que.push(max(que.front()+A, que.back()));
            x += A;
        }
        que.pop();
    }
    printf("%lld\n", que.back());
}