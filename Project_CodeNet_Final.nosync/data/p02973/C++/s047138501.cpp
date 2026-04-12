#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    multiset < int > X;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        
        auto it = X.lower_bound(x);
        
        if (it == X.begin()) X.insert(x);
        else {
            it--;
            X.erase(it);
            X.insert(x);
        }
    }
    
    printf("%d\n", (int)X.size());
    return 0;
}