#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int cnt = 1;
    for(int i=1;i<n;i++){
        bool possible = true;
        for(int j=i-1;j>=0;j--){
            if(arr[j] > arr[i])
                possible = false;
        }
        if(possible)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
