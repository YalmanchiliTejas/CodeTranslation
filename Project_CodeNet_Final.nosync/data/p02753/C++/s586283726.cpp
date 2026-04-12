#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>
#include <math.h>

using namespace std;

long long mod = 998244353;
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
    bool a = false, b = false;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            a = true;
        }
        else
        {
            b = true;
        }
    }
    if (a && b)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
