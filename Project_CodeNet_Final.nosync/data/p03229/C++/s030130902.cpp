#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map>
#include <math.h>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 998244353;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <ll> a(n);
    REP(i,n)cin >> a[i];
    sort(a.begin(),a.end());
    ll res1 = 0;
    ll res2 = 0;
    
    // パターン p1 ≥ p2 ≤ p3 ≥ ...
    ll right = a.size() - 1;
    ll left = 0;
    ll i = 0;
    while(right >= left)
    {
        if(i % 2 == 0)
        {
            //大きいものを2回足す
            res1 += 2 * a[right];
            --right;
        }
        else
        {
            //小さいものを2回ひかれる(0i0)
            res1 -= 2 * a[left];
            ++left;
        }
        ++i;
    }

    //全部2回ずつ足し引きしちゃってるので帳尻合わせ
    ll center = a.size() / 2;
    if(n % 2 == 0)
    {
        res1 -= a[center];//i%2 == 0の方
        res1 += a[center - 1];//i%2 == 1の方
    }
    else
    {
        //
        res1 -= a[center];
        res1 -= a[center + 1];//right側で*2しちゃっている
    }

    //パターンp1 ≤ p2 ≥ p3 ...
    right = a.size() - 1;
    left = 0;
    i = 0;
    while(right >= left)
    {
        if(i % 2 == 0)
        {
            //小さいものを2回ひかれる(0i0)
            res2 -= 2 * a[left];
            ++left;
        }
        else
        {
            //大きいものを2回足す
            res2 += 2 * a[right];
            --right;
        }
        ++i;
    }
    //全部2回ずつ足し引きしちゃってるので帳尻合わせ
    if(n % 2 == 0)
    {
        res2 -= a[center];//i%2 == 1の方
        res2 += a[center - 1];//i%2 == 0の方
    }
    else
    {
        res2 += a[center];
        res2 += a[center - 1];//left側で*2しちゃっている
    }

    cout << max(res1, res2) << endl;

    return 0;
}