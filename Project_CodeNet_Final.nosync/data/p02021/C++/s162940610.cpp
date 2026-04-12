#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n-1; i++){
        a[i+1] += a[i];
    }

    int ans = 0;
    for(;; ans++){
        bool ok = true;
        for(int i=0; i<n; i++){
            if(ans*(i+1) > a[i]){
                ok = false;
            }
        }
        if(!ok){
            ans--;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

