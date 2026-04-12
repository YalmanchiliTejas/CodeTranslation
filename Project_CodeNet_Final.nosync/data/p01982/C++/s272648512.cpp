#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(1){
        int n,l,r;
        cin >> n >> l >> r;
        if(n==0) break;

        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int ans = 0;
        for(int i=l; i<=r; i++){
            int minj = n;
            for(int j=0; j<n; j++){
                if(i%a[j] == 0){
                    minj = j;
                    break;
                }
            }
            if(minj%2==0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

