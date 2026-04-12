#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int a,r=0,l=0,ans=0;
    cin>>a;
    vector<int>c(100000000);
    vector<int>d(100000000);
    for(int i=0;i<a;i++){
        cin>>c[i];
        if(r<=c[i]){
            r=c[i];
            d[i]++;
        }
    
    }
    for(int i=0;i<a;i++){
        if(d[i]!=0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}