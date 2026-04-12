#include<iostream>
using namespace std;

int main(){
    int N;cin>>N;
    int H[25];
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(H[i]<H[j]&&i!=j)break;
            else if(i==j){
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
}