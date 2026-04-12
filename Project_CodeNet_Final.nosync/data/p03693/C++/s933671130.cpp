#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(NULL); cin.tie(NULL);
#define endl '\n'
using namespace std;


int main(){

        int n=0;
        int a;
        int t=3;
        while(t--){
            cin>>a;
            n=n*10 + a;
        }

        if(n%4==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 

    return 0;
}
