#include <iostream>

using namespace std;
typedef long long ll;
ll a[200010],fro[200010],bac[200010],dpfro[200010][2],dpbac[200010][2];
int main(){
    int i,n;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    if(n%2==0){
        ll ans1 = 0;
        dpfro[0][0] = 0; dpfro[0][1] = 0;
        dpfro[2][0] = a[0]; dpfro[2][1] = a[1];
        for(i=4;i<=n;i+=2){
            dpfro[i][0] = dpfro[i - 2][0] + a[i - 2];
            dpfro[i][1] = max(dpfro[i - 2][0],dpfro[i - 2][1]) + a[i - 1];
        }
        cout << max(dpfro[n][0],dpfro[n][1]) << endl;
    }else{
        dpfro[0][0] = 0; dpfro[0][1] = 0;
        dpfro[2][0] = a[0]; dpfro[2][1] = a[1];
        for(i=4;i<=n;i+=2){
            dpfro[i][0] = dpfro[i - 2][0] + a[i - 2];
            dpfro[i][1] = max(dpfro[i - 2][0],dpfro[i - 2][1]) + a[i - 1];
        }
        dpbac[n - 1][0] = 0; dpbac[n - 1][1] = 0;
        dpbac[n - 3][0] = a[n - 1]; dpbac[n - 3][1] = a[n - 2];
        for(i=n - 5;i>=0;i--){
            dpbac[i][0] = dpbac[i + 2][0] + a[i + 2];
            dpbac[i][1] = max(dpbac[i + 2][0],dpbac[i + 2][1]) + a[i + 1];
        }
        ll ans = -10000000000000000;
        for(i=0;i<n;i+=2){
            ans = max(ans,max(dpfro[i][0],dpfro[i][1]) + max(dpbac[i][0],dpbac[i][1]));
        }
        /*for(i=0;i<n;i++){
          cout << i << " " << dpfro[i][0] << " " << dpfro[i][1] << " " << dpbac[i][0] << " " << dpbac[i][1] << endl;
        }*/
        cout << ans << endl;
    }
}