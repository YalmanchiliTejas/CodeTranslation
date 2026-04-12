#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int main(void){
    while(1){
        int ans = 0;
        cin >> n;
        if(n == 0) break;
        vector<int> a(n);
        for(int i = 0;i < n;i++) cin >> a[i];
        
        sort(a.begin(),a.end());
        for(int i = 0;i < n;i++){
            if(i == 0 || i == n-1) continue;
            ans += a[i];
        }
        cout << ans/(n-2) << endl;
    }
    return 0;
}

