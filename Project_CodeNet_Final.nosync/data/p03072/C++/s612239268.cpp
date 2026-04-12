#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;cin>>n;
    int h;
    int max=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>h;
        if(h>=max){
            max=h;
            ans++;
        }
    }
    cout<<ans<<endl;
}

