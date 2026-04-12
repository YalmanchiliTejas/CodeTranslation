#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
int n, x, y;
int a[N];
ll ans1 = 0, ans2 = 0;

int main( ){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    int l = 1, r = n+1;
    int num = 1;
    y =  x = a[1];
    while (l < r) {
        if (num % 2) {
            r--;
            if (l < r) {
                ans1 += abs(a[r] - x);
                x = a[r];
            }
            r--;
            if (l < r) {
                ans1 += abs(a[r] - y);
                y = a[r];
            }
        }
        else {
            l++;
            if (l < r) {
                ans1 += abs(a[l] - x);
                x = a[l];
            }
            l++;
            if (l < r) {
                ans1 += abs(a[l] - y);
                y = a[l];
            }
        }
        num++;
    }
    num = 0;
    x = y = a[n];
    l = 0, r = n;
    while (l < r) {
        if (num % 2) {
            r--;
            if (l < r) {
                ans2 += abs(a[r] - x);
                x = a[r];
            }
            r--;
            if (l < r) {
                ans2 += abs(a[r] - y);
                y = a[r];
            }
        }
        else {
            l++;
            if (l < r) {
                ans2 += abs(a[l] - x);
                x = a[l];
            }
            l++;
            if (l < r) {
                ans2 += abs(a[l] - y);
                y = a[l];
            }
        }
        num++;
    }
    printf("%lld\n", max(ans1, ans2));
    return 0;
}
