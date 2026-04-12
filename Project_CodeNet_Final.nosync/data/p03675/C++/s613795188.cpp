#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    deque<int> dq;
    bool flip = false;

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (flip)
        {
            dq.push_front(x);
            flip = false;
        }
        else
        {
            dq.push_back(x);
            flip = true;
        }
    }

    if (flip) reverse(dq.begin(), dq.end());
    for (int t : dq) printf("%d ", t);
    printf("\n");
}
