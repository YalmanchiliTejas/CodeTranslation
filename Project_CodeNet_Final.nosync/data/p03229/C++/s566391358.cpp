#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 1, r = n - 2;
    long long cl = a[0], cr = a[n-1];
    long long sum = cr - cl;
    while(l <= r){
        if(cl > cr) swap(cl, cr);
        if(abs(cl - a[r]) < abs(cr - a[l])){
            sum += abs(cr - a[l]);
            cr = a[l];
            l++;
        }else{
            sum += abs(cl - a[r]);
            cl = a[r];
            r--;
        }
    }
    cout << sum << endl;
    return 0;
}