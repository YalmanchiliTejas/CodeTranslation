#include<bits/stdc++.h>

using namespace std;
int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    vector<long> t(n+1, -1);
    long r = 0;
    for(int i=0; i<n; i++) {
        auto it = lower_bound(t.begin(), t.end(), a[i])-1;
        if(*it == -1) r++;
        *it = a[i];
    }
    cout << r << endl;
}


