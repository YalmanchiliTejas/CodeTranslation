#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main() {
    int N; cin>>N;
    int H[N];
    REP(i,N){
        cin>>H[i];
    }
    int ans=1;
    int tmp=H[0];
    for(int i=1;i<N;i++){
        if(H[i]>=tmp){
            ans++;
            tmp=H[i];
        }
    }
    cout<<ans<<endl;
}