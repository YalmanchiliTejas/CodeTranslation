#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    deque<long long> d;
    for (int i = 0; i < N; i++)
    {
        long long A;
        cin >> A;
        auto itr = lower_bound(d.begin(), d.end(), A);
        if (itr == d.begin())
        {
            d.push_front(A);
        }
        else
        {
            --itr;
            *itr = A;
        }
    }
    cout << d.size() << endl;
}