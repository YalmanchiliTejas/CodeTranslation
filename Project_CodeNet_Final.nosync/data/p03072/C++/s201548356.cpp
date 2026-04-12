#include<iostream>
using namespace std;

int main(){
    int N,H[25],dif,ans=0,i,j,count;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>H[i];
    }
    for(i=0;i<N;i++){
        count=0;
        for(j=0;j<i;j++){
            dif=H[i]-H[j];
            if(dif<0){
                count++;
            }
        }
        if(count==0){
            ans++;
        }
    }
    cout<<ans<<endl;
}
