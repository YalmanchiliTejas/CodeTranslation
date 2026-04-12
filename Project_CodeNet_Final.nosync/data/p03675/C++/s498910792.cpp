#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    deque<int> deq;
    bool f = true;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if(f)
        {
            deq.push_back(a);
            f = 0;
        }
        else
        {
            deq.push_front(a);
            f = 1;
        }
    }
    if(f)
    {
        for(int i = 0; i < n; i++)
            cout << deq[i] << ' ';
    }
    else
    {
        for(int i = n - 1; i >= 0; i--)
            cout << deq[i] << ' ';
    }
    return 0;
}
