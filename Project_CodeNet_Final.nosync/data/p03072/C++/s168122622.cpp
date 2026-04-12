#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int ans=0,max=0,N;cin>>N;
    REP(i,N){
        int H;
        cin>>H;
        if(max<=H){
            max=H;
            ans++;
        }
    }
    cout<<ans<<endl;
}