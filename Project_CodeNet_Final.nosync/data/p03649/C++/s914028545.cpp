#include <iostream>
#include <queue>

using namespace std;

int main()
{
    long long n; cin >> n;
    priority_queue<long long> queue;
    for (long long i = 0; i < n; i++)
    {
        long long val; cin >> val;
        queue.push(val);
    }
    long long res = 0;
    while (queue.top() >= n)
    {
        priority_queue<long long> queueBack;
        long long cur = queue.top();
        queue.pop();
        long long div = cur / n;
        res += div;
        long long mod = cur % n;
        cur = mod;
        queueBack.push(cur);
        while (!queue.empty())
        {
            queueBack.push(queue.top() + div);
            queue.pop();
        }
        queue = queueBack;
    }
    cout << res << '\n';
    return 0;
}