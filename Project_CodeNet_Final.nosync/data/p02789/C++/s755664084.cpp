#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    //int ans=0;
    bool ans=false;
    int N,M;
    
    cin>>N>>M;
    if(M==N){
        ans=true;
    }
    
    //cout<<ans<<endl;

   if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}