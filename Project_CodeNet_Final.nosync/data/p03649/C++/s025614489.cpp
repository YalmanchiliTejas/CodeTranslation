//
//  main.cpp
//  E
//
//  Created by Vadim Zakharenko on 29/07/2017.
//  Copyright © 2017 Vadim Zakharenko. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a[111];
int n;

int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for(;;) {
        long long iter = 0;
        for (int i = 1; i <= n; i++) {
            iter += a[i] / n;
        }
        ans += iter;
        for (int i = 1; i <= n; i++) {
            long long old_a = a[i];
            a[i] %= n;
            a[i] += iter - old_a / n;
        }
        if (*max_element(a + 1, a + n + 1) < n) {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
