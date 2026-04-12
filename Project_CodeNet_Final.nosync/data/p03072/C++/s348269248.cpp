#include <iostream>
using namespace std;
int main(){
    int N = 0;
    int H[20] = {0};
    cin>>N;
    
    for(int i = 0;i < N;i++){
        cin>>H[i];
    }
    
    int res = 0;
    for(int i = 0;i < N;i++){
        bool hi = true;
        for(int j = 0;j < i;j++){
            
        if(H[j] > H[i]){
             hi = false;
            break;
            
        }
    }
    
    if(hi)res++;
    }
    
    cout<<res;
    
    return 0;
}
