#include <bits/stdc++.h>
using namespace std;

int n;
int a[200050], num[200050];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i], a[i] = num[i];
    sort(num, num+n);
    for(int i = 0; i < n; i++){
        if(a[i] < num[n/2]) cout << num[n/2] << endl;
        else cout << num[n/2-1] << endl;
    }
}