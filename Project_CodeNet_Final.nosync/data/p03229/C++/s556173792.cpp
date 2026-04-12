
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e5;

int n;
int a[N+5];

int main()
{
    std::ios::sync_with_stdio(false);
    while ( cin >> n )
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);

        deque<int> dq;

        int l = 0;
        int r = n-1;
        int left = a[l];
        int right = a[r];

        ll ans = abs(a[l]-a[r]);

        dq.push_front(a[l]);
        dq.push_back(a[r]);
        l++;
        r--;

        while (l <= r)
        {
            int lfront = abs(a[l] - left);
            int lback = abs(a[l] - right);
            int rfront = abs(a[r] - left);
            int rback = abs(a[r] - right);

            //cout << lfront << " " << lback << endl;
            //cout << rfront << " " << rback << endl;

            int lmx = max(lfront, lback);
            int rmx = max(rfront, rback);

            if (lmx > rmx)
            {
                if (lfront > lback)
                {
                    dq.push_front(a[l]);
                    left = a[l];
                    ans += lfront;
                }
                else
                {
                    dq.push_back(a[l]);
                    right = a[l];
                    ans += lback;
                }

                l++;
            }
            else
            {
                if (rfront > rback)
                {
                    dq.push_front(a[r]);
                    left = a[r];
                    ans += rfront;
                }
                else
                {
                    dq.push_back(a[r]);
                    right = a[r];
                    ans += rback;
                }
                r--;
            }
        }

        //for (int i = 0; i < n; i++)
        //{
            //cout << dq[i] << " ";
        //}
        //cout << endl;

        cout << ans << endl;
    }

    return 0;
}
