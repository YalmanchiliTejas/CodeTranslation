#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int h[n];
    for(int i = 0;i < n;i++) {
        cin >> h[i];
    }

    int max = h[0];
    int sam = 1;
    for(int i = 1;i < n;i++) {
        if(max<=h[i]) {
            sam++;
            max = h[i];
        }
    }
    cout << sam << endl;

}