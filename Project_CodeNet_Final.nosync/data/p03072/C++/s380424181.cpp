#include <iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int h[n];
    for (int i=0;i<n;i++){
        cin>>h[i];
    }
    int mx = 0;
    int ans = 0;
    for (int i=0;i<n;i++){
        if (mx<=h[i]){
            ans++;mx=h[i];
        }
    }
    cout<<ans;
}
