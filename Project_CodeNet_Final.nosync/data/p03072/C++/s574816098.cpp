#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    int ans = 0;
    int maxh = -1;
    for (int i = 0; i < N; i++)
    {
        int h;
        scanf("%d", &h);
        if (h >= maxh)
        {
            ans++;
            maxh = h;
        }
    }

    printf("%d\n", ans);
}