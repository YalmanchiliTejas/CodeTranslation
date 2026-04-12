#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n+5];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int tinggi=arr[0],ans=1;
    for(int i=1; i<n; i++){
        if(arr[i]>=tinggi)ans++;
        tinggi = max(tinggi,arr[i]);
    }
    cout << ans <<endl;
}
