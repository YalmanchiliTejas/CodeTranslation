#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[21];
    for(int i=0;i<n;i++)cin >> a[i];
    int ans = 1;
    int mx = a[0];
    for(int i=1;i<n;i++){
if(mx <= a[i]){
//    cout << i << endl;
    ans++;
mx = a[i];
}
    }
    cout << ans << endl;
    return 0;
}