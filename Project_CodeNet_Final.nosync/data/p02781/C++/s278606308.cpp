#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define ll long long

int main() {
    string a;
    cin >> a;
    int k;
    cin >> k;
    int len = a.size();
    long long e = 0;
    if (k == 1) {
        e += 9 * (len - k);
        e += a[0] - '0';
    }
    if (k == 2) {
        if (len > 1) {
            int i;
            for (i = 1; i <= len - k; i++) {
                e += 81 * i;
            }
            e += i * 9 * (a[0] - '0' - 1);
            for (int j = 1; j < len; j++) {
                if (a[j] != '0') {
                    e += a[j] - '0';
                    e += 9 * (i - j);
                    break;
                }
            }
        }
    }
    if (k == 3) {
        if (len > 2) {
            int i;
            for (i = 1; i <= len - k; i++) {
                e += 729 * (i + 1) * i / 2;
            }
            i++;
            e += (a[0] - '0' - 1) * (i - 1) * i / 2 * 81;
            for (int j = 1; j < len; j++) {
                if (a[j] != '0') {
                    e += (a[j] - '0' - 1) * (i - j) * 9;
                    for (int l = j + 1; l < len; l++) {
                        if (a[l] != '0') {
                            e += a[l] - '0';
                            e += 9 * (i - l);
                            break;
                        }
                    }
                    e += (i - j - 1) * (i - j) / 2 * 81;
                    break;
                }
            }
        }
    }
    printf("%lld\n", e);
    return 0;
}