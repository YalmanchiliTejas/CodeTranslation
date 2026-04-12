#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> x(n);
    for(int i = 0; i < n; i++) x[i] = a[i];

    sort(a.begin(), a.end());
    int l = a[n/2 - 1];
    int u = a[n/2];
    //cout << l << " " << u << endl;
    
    for(int i = 0; i < n; i++){
        if(x[i] <= l) cout << u << endl;
        else cout << l << endl;
    }
    return 0;
}