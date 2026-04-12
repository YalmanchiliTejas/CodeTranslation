#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int n; scanf("%d", &n);
    vector<int> v(n + 1, 1e9); 
    for(int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        *upper_bound(v.begin(), v.end(), -a) = -a; 
    }
    printf("%d\n", lower_bound(v.begin(), v.end(), 1e9) - v.begin());
}