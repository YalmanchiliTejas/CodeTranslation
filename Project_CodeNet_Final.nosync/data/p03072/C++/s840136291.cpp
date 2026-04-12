#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int H[N];
    for(int i=0;i<N;i++) cin>>H[i];

    int flag[N] = {};
    flag[0] = 1;
    int maxhigh = H[0];
    int ans=1;

    for(int i=0;i<N-1;i++){
        if(H[i]<=H[i+1]&&maxhigh<=H[i+1]){
        ans++;
        maxhigh=H[i+1];
        }
    }

    cout<<ans<<endl;
    return 0;
}