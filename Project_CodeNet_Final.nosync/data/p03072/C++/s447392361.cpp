#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> H(n);
    int ans=0,l=0;
    for (int i = 0; i < n;i++){
        cin >> H[i];
    }
        for (int i = 0; i < n; i++)
        {
            if (H[i] >= l)
            {
                ans++;
                l = H[i];
            }
        }
    cout << ans << endl;
}