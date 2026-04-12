#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        bool ok = true;
        for(int j=i-1;j>=0;j--){
            if(arr[i]<arr[j])
            {
                ok = false;
                break;
            }
        }
        if(ok)
        ans++;
                
    }

    cout << ans;
}