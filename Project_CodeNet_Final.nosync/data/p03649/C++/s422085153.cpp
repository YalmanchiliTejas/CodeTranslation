#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[52];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > (n - 1) * n){
            ans += ((a[i] - (n - 1) * n - 1) / (n + 1)) * (n + 1);
            a[i] -= ((a[i] - (n - 1) * n - 1) / (n + 1)) * (n + 1);
        }
    }
    while(true){
        bool yet = false;
        for(int i = 0; i < n; i++){
            if(a[i] >= n){
                for(int j = 0; j < n; j++) a[j]++;
                a[i] -= n + 1;
                ans++;
                yet = true;
            }
        }
        if(!yet) break;
    }
    cout << ans << endl;
}