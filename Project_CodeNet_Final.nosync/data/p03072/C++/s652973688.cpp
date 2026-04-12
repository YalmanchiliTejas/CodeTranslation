#include <iostream>
using namespace std;
int main(){
    int N;
    //旅館の数
    cin>>N;
    int H[N];
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    int Max=H[0];
    int count=1;
    for(int i=1;i<N;i++){
        if(Max<=H[i]){
            count=count+1;
            Max=H[i];
        }
    }
    cout<<count<<endl;
    return 0;
}