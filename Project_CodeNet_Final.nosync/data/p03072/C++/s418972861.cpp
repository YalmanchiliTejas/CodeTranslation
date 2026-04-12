///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

void intin(int *a)
{
        cin >> *a;
}

void intinl1(auto *v, int count)
{
        for (int i = 0; i < count ; ++i) {
                int a;
                cin >> a;
                v->push_back(a);
        }
}

void intinl2(auto *v, int count)
{
        for (int i = 0; i < count ; ++i) {
                int a, b;
                cin >> a >> b;
                v->push_back({a, b});
        }
}

void intinl3(auto *v, int count)
{
        for (int i = 0; i < count ; ++i) {
                int a, b, c;
                cin >> a >> b >> c;
                v->push_back({a, b, c});
        }
}

void intina(auto *v, int count)
{
        intinl1(v, count);
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
        int n;
        vector<int> hlist;

        intin(&n);
        intina(&hlist, n);

        int hmax = 0;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
                if (hlist[i] >= hmax) {
                        ans += 1;
                        hmax = hlist[i];
                }
        }

        cout << ans;

        return 0;
}

///////////////////////////////////////////////////////////////////////////////
