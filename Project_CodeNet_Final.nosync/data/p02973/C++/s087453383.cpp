#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> li;
    li.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] <= li[li.size()-1]) {
            li.push_back(a[i]);
        } else {
            for (int j = 0; j < li.size(); j++) {
                if (li[j] < a[i]) {
                    li[j] = a[i];
                    break;
                }
            }
        }
    }
    printf("%d\n", li.size());
}