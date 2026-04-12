#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

int main(){
    
    while(true){
        int n;
        cin >> n;
        
        if(n == 0) break;
        
        vector<int> a(n);
        int minv = 1001;
        int maxv = -1;
        int sum = 0;
        rep(i,n){
            cin >> a[i];
            minv = min(minv,a[i]);
            maxv = max(maxv,a[i]);
            sum += a[i];
        }
        sum = sum - minv - maxv;
        sum /= (n-2);
        
        cout << sum << endl;
    }
}



