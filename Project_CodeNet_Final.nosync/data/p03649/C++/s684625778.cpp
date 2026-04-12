#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long arr[60];
long long res;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(long long i=1;i<=100000;i++){
        for(long long j=1;j<=n;j++){
            if(arr[j]>=n){
                res += arr[j]/n;
                
                for(long long k=1;k<=n;k++){
                    if(k == j){
                        continue;
                    }
                    arr[k]+=(arr[j]/n);
                }
                arr[j]-=(arr[j]/n)*n;
            }
        }
    }
    cout<<res<<endl;
}