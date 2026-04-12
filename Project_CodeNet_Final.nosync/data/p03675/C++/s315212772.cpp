#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n ; i++) {
        cin >> a[i];
    }

    int flag = 0, l = 0, r = n-1;
    for (int i = n-1; i >= 0; i--) {
        if (flag == 0) {
            b[l] = a[i];
            l++;
            flag = 1;
        }
        else {
            b[r] = a[i];
            r--;
            flag = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}
