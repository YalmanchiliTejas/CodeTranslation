#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m=0,cnt=0;
    cin>>n;

    for(int i=0; i<n; i++){
        int h;
        cin>>h;
        if(h>=m){
            m=h;
            cnt++;
        }
    }

    cout<<cnt<<endl;
    return 0;
}
