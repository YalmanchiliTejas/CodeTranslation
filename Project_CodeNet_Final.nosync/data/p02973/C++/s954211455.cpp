#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<long> arr(N);
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    reverse(arr.begin(), arr.end());
    long DP[N];
    for(int i=0;i<N;++i){
        DP[i] = 1e9+7;
    }
    int l, r, m;
    for(int i=0;i<N;++i){
        l = 0;
        r = N-1;
        while(l<r){
            m = (l+r)/2;
            if(DP[m]>arr[i]){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        DP[l] = arr[i];
    }
    int ans = 0;
    l = 0;
    r = N-1;
    while(l<r){
        m = (l+r)/2;
        if(DP[m]==1e9+7){
            r = m;
        }
        else{
            l = m + 1;
        }
    }
    if(DP[l]==1e9+7)cout<<l<<endl;
    else cout<<l+1<<endl;
}
