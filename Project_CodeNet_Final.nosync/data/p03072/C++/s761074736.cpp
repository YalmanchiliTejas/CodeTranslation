#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    int h;
    int s,ans=0;
    for(int i=0;i<n;i++){
        cin>>h;
        
        if(s<=h)  ans++;
        s = max(s,h);
    }
    cout<<ans<<endl;
    
}

