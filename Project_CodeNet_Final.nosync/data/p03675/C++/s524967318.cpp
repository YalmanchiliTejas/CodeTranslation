#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    int n;
    cin>>n;
    int k[n],ans[n];
    
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    
    int now=0;
    for(int i=n-1;i>-1;i=i-2){
        ans[now]=k[i];
        now++;
    }
    
    if(n%2){
        for(int i=1;i<n;i=i+2){
        ans[now]=k[i];
        now++;
    }
    }
    else{
        for(int i=0;i<n;i=i+2){
        ans[now]=k[i];
        now++;
    }
    }
    
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if(i<n-1){
            cout<<" ";
        }
    }
}
