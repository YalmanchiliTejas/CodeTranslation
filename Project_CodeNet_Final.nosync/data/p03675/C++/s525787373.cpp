#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<int> deq;
    for (int i = n; i > 0; i--)
    {
        int tmp;
        cin >> tmp;
        if (i % 2) deq.push_front(tmp);
        else deq.push_back(tmp);
    }
    for (auto v : deq) cout << v << " ";
}