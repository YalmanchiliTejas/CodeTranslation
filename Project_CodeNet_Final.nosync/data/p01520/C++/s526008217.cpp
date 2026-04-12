#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,t,e;
    cin>>n>>t>>e;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        int xi=x;
        while(x<=t+e){
            if(x>=t-e&&x<=t+e){
                cout<<i+1<<endl;
                return 0;
            }
            x+=xi;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
