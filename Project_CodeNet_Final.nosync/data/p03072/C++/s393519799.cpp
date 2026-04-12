#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int N,count=0,ans=0;
    cin>>N;
    vector<int> H(N);
    rep(i,N){
        cin>>H[i];
    }
    rep(i,N) {
        count = 0;
        rep(j,i){
            if (H[i] < H[j]) {
                count = 1;
            }
        }
        if (count==0){
            ans++;
    }
    }
    cout<<ans<<endl;
    return 0;
}