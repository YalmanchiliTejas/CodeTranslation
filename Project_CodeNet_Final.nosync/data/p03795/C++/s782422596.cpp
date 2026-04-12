#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,sum;
    cin>>N;

    for(int i=0;i<N;i++){
        sum+=800;
        if((i+1)%15==0){
            sum-=200;
        }
    }
    cout<<sum<<endl;
   
    return 0;
}