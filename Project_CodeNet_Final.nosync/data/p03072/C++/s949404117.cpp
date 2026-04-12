#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    int h[30];
    for(int i=0;i<n;i++)cin>>h[i];
    int ans=1,m=h[0];
    for(int i=1;i<n;i++){
        if(m<=h[i]){
            ans++;
            m=h[i];
        }
    }
    cout<<ans<<endl;
}
