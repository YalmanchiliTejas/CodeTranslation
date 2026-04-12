#include "bits/stdc++.h"
using namespace std;

const int N = 2 * 1e5 + 5;
int a[N], b[N];
deque<int> d;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(i&1) d.push_front(a[i]);
        else d.push_back(a[i]);
    }

    if(n&1) reverse(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++)
    {
        cout << d[i] << ' ';
    }
}
