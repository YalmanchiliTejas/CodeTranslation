#include<iostream>
using namespace std;

int main(){
    int n,highest;
    cin>>n;

    int ans=0;

    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    highest=h[0];

    for(int i=0;i<n;i++){
        if(h[i]>=highest){
            ans++;
            highest=h[i];
        }
    }

    cout<<ans<<endl;

    return 0;
}
