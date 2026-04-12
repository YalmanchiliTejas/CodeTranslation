#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int cnt = 0;
deque<int> q;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        auto it = lower_bound(q.begin(), q.end(), a);
        if (it == q.begin())
        {
            q.push_front(a);
        }
        else
        {
            q[it - q.begin() - 1] = a;
        }
    }

    cout << q.size() << endl;
}