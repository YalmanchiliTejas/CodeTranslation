#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(vector<ll> ar) {
    int n = ar.size();
    ll rs = 0;
    for(int i = 1; i < n; i++) {
        rs += abs(ar[i] - ar[i - 1]);
    }
    return rs;
}

int main()
{
    int n; cin >> n;
    deque<ll> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a.begin(), a.end());

    ll nax = 0;

    {
        deque<ll> deq = a;
        vector<ll> ar(n);
        for(int i = 1; i < n - 1; i++) {
            if(i & 1)ar[i] = deq.back(), deq.pop_back();
            else ar[i] = deq.front(), deq.pop_front();
        }
        ar[0] = deq.front();
        ar[n - 1] = deq.back();
        nax = max(nax, calc(ar));
    }

    {
        deque<ll> deq = a;
        vector<ll> ar(n);
        for(int i = 1; i < n - 1; i++) {
            if(i % 2 == 0)ar[i] = deq.back(), deq.pop_back();
            else ar[i] = deq.front(), deq.pop_front();
        }
        ar[0] = deq.front();
        ar[n - 1] = deq.back();
        nax = max(nax, calc(ar));
    }
    cout << nax << endl;

}