#include <iostream>
#include "string.h"
#include <algorithm>
#include <vector>
#include <stdio.h>
#include "math.h"
#include <queue>
using namespace std;

int a[100010];
int b[100010];

int main() {

    int n;
    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", a+i);
    sort(a, a+n);

    int l = 1;
    int r = n-1;
    deque<int> q;
    q.push_back(a[0]);
    for (int i=1; i<n; i++) {

        int x, y, z, w;
        x = abs(q.back() - a[l]);
        y = abs(q.back() - a[r]);
        z = abs(q.front() - a[l]);
        w = abs(q.front() - a[r]);

        if (x >= y && x >= z && x >= w) {
            q.push_back(a[l++]);
        }
        else if (x <= y && y >= z && y >= w) {
            q.push_back(a[r--]);
        }
        else if (x <= z && y <= z && z >= w) {
            q.push_front(a[l++]);
        }
        else {
            q.push_front(a[r--]);
        }

    }

    int i = 0;
    while (!q.empty()) {
        b[i++] = q.front();
        q.pop_front();
    }

    long long sum = 0;
    for (int i=1; i<n; i++) sum += abs(b[i] - b[i-1]);

    cout<<sum<<endl;

    return 0;
}
