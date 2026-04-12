#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int H[N];
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    int a=0;
    int l=0;
    for(int i=0;i<N;i++){
        if(a<=H[i]){
            l+=1;
            a=H[i];
        }
    }
    cout<<l<<endl;
    return 0;
    }
