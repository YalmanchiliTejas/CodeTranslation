#include <cstdio>
#include <deque>

int n;
std::deque<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 0, a; i < n; ++i) {
        scanf("%d", &a);
        if ((i ^ n) & 1) q.push_front(a); else q.push_back(a);
    }

    for (int i = 0; i < n; ++i) printf("%d%c", q[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
