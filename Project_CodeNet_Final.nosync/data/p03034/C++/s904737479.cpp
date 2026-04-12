#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


using namespace std;

int n;
int a[500000];

vector<long long> rad;

struct keks{
    int LR, p, id;
};

vector<keks> suffQ;
vector<keks> prefQ;

void res(int A, int B)
{
    int g = __gcd(A, B);
    if (A == B + g)
    {
        if (A + B < n)
            return;
    }
    int D = A - B;
    suffQ.push_back({A, D, rad.size()});
    prefQ.push_back({n - A, D, rad.size()});
    rad.push_back(0);
    long long ans = 0;
    int pos = 0;
}


long long sums[500000];
long long smus[500000];

int main()
{
    cin >> n;
    n--;
    for (int i = 0; i < n + 1; i++) cin >> a[i];
    for (int B = 1; B <= n; B++)
    {
        int x = n - B;
        for (int d = 1; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                int amb = d;
                int A = amb + B;

                if (A > B)
                    res(A, B);

                amb = x / d;
                A = amb + B;

                if (A > B)
                    res(A, B);
            }
        }
    }
    sort(prefQ.begin(), prefQ.end(), [&](keks a, keks b) {
             return a.LR < b.LR;
         });
    sort(suffQ.begin(), suffQ.end(), [&](keks a, keks b) {
             return a.LR > b.LR;
         });
    /*for (int i = 0; i < prefQ.size(); i++)
    {
        cout << prefQ[i].LR << " " << prefQ[i].p << " " << prefQ[i].id << endl;
    }
    cout << endl;
    for (int i = 0; i < suffQ.size(); i++)
    {
        cout << suffQ[i].LR << " " << suffQ[i].p << " " << suffQ[i].id << endl;
    }
    cout << endl;*/
    int iq = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                sums[j] += a[i];
                if (j * j != i)
                {
                    sums[i / j] += a[i];
                }
            }
        }
        while (iq < prefQ.size() && prefQ[iq].LR == i)
        {
            rad[prefQ[iq].id] += sums[prefQ[iq].p];
            iq++;
        }
    }
    iq = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j * j <= (n - i); j++)
        {
            if ((n - i) % j == 0)
            {
                smus[j] += a[i];
                if (j * j != (n - i))
                {
                    smus[(n - i) / j] += a[i];
                }
            }
        }
        while (iq < suffQ.size() && suffQ[iq].LR == i)
        {
            rad[suffQ[iq].id] += smus[suffQ[iq].p];
            iq++;
        }
    }
    cout << *max_element(rad.begin(), rad.end());
}
