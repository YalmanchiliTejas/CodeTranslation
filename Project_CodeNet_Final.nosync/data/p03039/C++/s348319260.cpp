#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

// long long mod = 998244353;
long long mod = 1000000007;
vector<long long> fact(1000001);
vector<long long> invFact(1000001);

long long binpow(long long x, long long k)
{
    if (k == 0)
    {
        return 1LL;
    }
    long long temp = binpow(x, k / 2);
    if (k % 2 == 1)
    {
        return (((temp * temp) % mod) * x) % mod;
    }
    else
    {
        return (temp * temp) % mod;
    }
}

long long modular_inverse(long long x)
{
    return binpow(x, mod - 2);
}

long long binomial(long long n, long long k)
{
    long long rez = 1;
    for (long long i = n - k + 1; i <= n; i++)
    {
        rez *= i;
        rez %= mod;
    }
    long long temp = 1;
    for (long long i = 1; i <= k; i++)
    {
        temp *= i;
        temp %= mod;
    }
    rez *= modular_inverse(temp);
    rez %= mod;
    return rez;
}

int fi(int a, vector<int> &p)
{
    if (p[a] != p[p[a]])
    {
        p[a] = fi(p[a], p);
    }
    return p[a];
}

void uni(int a, int b, vector<int> &p)
{
    int x = fi(a, p), y = fi(b, p);
    if (x != y)
    {
        p[x] = y;
    }
}

long long euclidianDistanceSquared(pair<int, int> a, pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

double euclidianDistanceSquared(pair<double, double> a, pair<double, double> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

double euclidianDistance(pair<double, double> a, pair<double, double> b)
{
    return sqrt(euclidianDistanceSquared(a, b));
}

bool circleIntersections(pair<double, double> pos1, double r1, pair<double, double> pos2, double r2, pair<double, double> &int1, pair<double, double> &int2)
{
    double d = euclidianDistance(pos1, pos2);
    if (r1 + r2 < d || d < fabs(r1 - r2))
    {
        return false;
    }
    double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
    double h = sqrt(r1 * r1 - a * a);
    pair<double, double> pos3 = { pos1.first + a * (pos2.first - pos1.first) / d, pos1.second + a * (pos2.second - pos1.second) / d };
    int1.first = pos3.first + h * (pos2.second - pos1.second) / d;
    int1.second = pos3.second - h * (pos2.first - pos1.first) / d;
    int2.first = pos3.first - h * (pos2.second - pos1.second) / d;
    int2.second = pos3.second + h * (pos2.first - pos1.first) / d;
    return true;
}

class SegmentTree
{
public:
    class Node
    {
    public:
        vector<int> value;
        Node *l, *r;
        int left, right;

        Node(int x, int y)
        {
            value = vector<int>(26, 0);
            l = nullptr;
            r = nullptr;
            left = x;
            right = y;
        }

        void update(int p, char c)
        {
            if (left > p || p > right)
            {
                return;
            }
            if (left == p && p == right)
            {
                for (int i = 0; i < 26; i++)
                {
                    value[i] = 0;
                }
                value[c - 'a'] = 1;
                return;
            }
            if (l == nullptr)
            {
                int mid = (left + right) / 2;
                l = new Node(left, mid);
                r = new Node(mid + 1, right);
            }
            l->update(p, c);
            r->update(p, c);
            for (int i = 0; i < 26; i++)
            {
                value[i] = l->value[i] + r->value[i];
            }
        }

        int query(int x, int y)
        {
            if (left > y || x > right)
            {
                return 0;
            }
            if (x <= left  && right <= y)
            {
                int rez = 0;
                for (int i = 0; i < 26; i++)
                {
                    if (value[i] != 0)
                    {
                        rez |= (1 << i);
                    }
                }
                return rez;
            }
            if (l == nullptr)
            {
                return 0;
            }
            return l->query(x, y) | r->query(x, y);
        }
    };

    Node *root;
    SegmentTree(int n)
    {
        root = new Node(0, n - 1);
    }

    void update(int p, char c)
    {
        root->update(p, c);
    }

    int query(int x, int y)
    {
        return root->query(x, y);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    

    int n, m, k;
    cin >> n >> m >> k;
    if (n > m)
    {
        swap(n, m);
    }
    long long totalDist = 0;
    for (int i = 0; i < n; i++)
    {
        long long localSum = 0;
        for (int j = 0; j < n; j++)
        {
            localSum += abs(j - i);
        }
        long long localSum2 = 0;
        for (int j = 0; j < m; j++)
        {
            localSum2 += localSum + n * j;
        }
        long long x1 = 1, x2 = m - 1;
        for (int j = 0; j < m; j++)
        {
            totalDist += localSum2;
            localSum2 -= localSum + n * x2;
            localSum2 += localSum + n * x1;
            x1++;
            x2--;
        }
    }
    totalDist /= 2;
    totalDist %= mod;
    // cout << totalDist << '\n';
    cout << (totalDist * binomial(n * m - 2, k - 2)) % mod << '\n';
    return 0;
}
