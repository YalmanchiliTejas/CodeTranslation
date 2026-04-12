#include <bits/stdc++.h>
using namespace std;
int n, k, intersect, dist;
pair <int, int> a[2];

#define F first
#define S second

bool check(long long num) {
    int get = a[1].S - min(a[0].F, a[1].F) - intersect; /// getfull point
    int cost = a[1].S - a[0].S + abs(a[0].F - a[1].F); /// cost to getfull

    if(cost == 0) {
        return num/2 >= k;
    }


    if(num < cost) {
        long long xx = num - dist;
        return (xx >= k);
    }

    long long ret = get;
    num -= cost;

    long long val1 = ret + num/2;

    long long val2 = ret;
    long long block = num/cost;
    if(block >= n-1) {
        val2 += 1ll*(n-1)*get;
        val2 += (num - 1ll*(n-1)*cost)/2;
    } else {
        val2 += 1ll*block*get;
        int du = num % cost;
        val2 += max(du/2, max(0, du-dist));
    }
    ret = max(val1, val2);
    return ret >= k;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(".inp", "r")) freopen(".inp", "r", stdin);
    int x; cin >> x;
    cout << (x >= 30 ? "Yes" : "No");

    return 0;
}
