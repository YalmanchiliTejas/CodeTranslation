#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int hall=0,cnt=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>=hall){
            hall = tmp;
            cnt++;
        }
    }
    cout<<cnt;
}
