#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
using namespace std;

int main(){
    int N,max,sum=1,H[30];
    cin>>N>>H[0];
    max=H[0];
    for(int i=1;i<N;++i){
        cin>>H[i];
        if(H[i]>=max){
            sum+=1;
            max=H[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}