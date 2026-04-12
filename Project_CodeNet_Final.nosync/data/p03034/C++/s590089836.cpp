#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

int n;
int s[N];
bool kt[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];

    long long res = 0;
    for (int i = 1; i < n - 1; ++i) {
        long long sum = 0;
        vector<int> modified;
        for (int l = i, r = n - 1 - i; l + i < n - 1; l += i, r -= i) {
            if (!kt[l]) {
                kt[l] = true;
                sum += s[l];
                modified.push_back(l);
            }
            else break;
            if (!kt[r]) {
                kt[r] = true;
                sum += s[r];
                modified.push_back(r);
            }
            else break;
            res = max(res, sum);
        }
        for (int x : modified) kt[x] = false;
    }
    cout << res;
    return 0;
}
