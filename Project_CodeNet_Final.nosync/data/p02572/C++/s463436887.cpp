#include <bits/stdc++.h>
using namespace std;

int modinv(long long a, long long m = 1000000007){
    for(long long i=0;i<m;i++){
        if( ((i*m+1)%a) == 0 ){
            return i;
        }
    }
    return -1;
}

int main(){
    long long n,a[200010];
    long long m = 1000000007;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int answer = 0;
    long long jsum[200010];

    for(int j=n-1; j>=0; j--){
        if(j==n-1){
            jsum[j] = a[j];
        }else{
            jsum[j] = (jsum[j+1] + a[j])%m;
        }

    }
    
    for(int i=1; i<n; i++){
        answer = (answer + jsum[i]*a[i-1])%m;
    }

    cout << answer;
}