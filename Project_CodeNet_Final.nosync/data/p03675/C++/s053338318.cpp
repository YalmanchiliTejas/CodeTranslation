#include <bits/stdc++.h>
using namespace std;
deque <int> Q;
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
    {
        int a;
        scanf("%d", &a);
        if ((n - i) & 1) Q.push_back(a); else Q.push_front(a);
    }
    while (!Q.empty()) printf("%d ", Q.front()), Q.pop_front();
}
