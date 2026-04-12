#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int curmax=-1;
    int ans=0;
    for(int i=0;i<n;++i){
        if(a[i]>=curmax){
            ++ans;
            curmax=a[i];
        }
    }
    cout<<ans<<endl;
}

