#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] = -arr[i];
    }
    vector<int> val(n+1, 1e9+7);
    val[0] = arr[0];
    int mx = 1;
    for(int i = 1; i < n; i++){
        auto lb = upper_bound(val.begin(), val.begin()+mx, arr[i] );
        val[(lb - val.begin())] = arr[i];
        if( (lb - val.begin()) == mx )
            mx++;
    }

    cout << mx << endl;
    return 0;
}