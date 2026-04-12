#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    vector<int>H(N);
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    int ans=0;
    int now=H[0];
    for(int i=0;i<N;i++){
        if(H[i]>=now){
            ans++;
            now=H[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}