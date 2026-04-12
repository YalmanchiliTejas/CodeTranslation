#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector <int> seq;
    for (int i = n - 1; i >= 0; i--) {
        int ind = upper_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
        if (ind < seq.size()) seq[ind] = a[i];
        else seq.push_back(a[i]);
    }
    printf("%d\n", int(seq.size()));
    return 0;
}
