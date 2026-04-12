#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    long long ans;
    int x,y;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int mina = a[0];
    int maxa = a[n-1];
    ans = maxa-mina;
    if(n>2){
    for(int i=1;i<n/2;i++){
            x = a[n-i-1] - mina;
            y = maxa - a[i];
            mina = a[i];
            maxa = a[n-i-1];
            ans = ans + x + y;
    }
    }
    if(n%2==1){
        ans = ans + max(abs(a[n/2]-maxa),abs(a[n/2]-mina));
    }
    cout << ans << endl;
    return 0;
}