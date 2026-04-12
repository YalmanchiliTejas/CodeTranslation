#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int H[N];
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    int ans=1;
    for(int i=1;i<N;i++){
        int count=0;
        for(int j=0;j<i;j++){
           if(H[i]>=H[j]){count++;}
        }
        if(count==i){ans++;}
    }
    cout<<ans;
    return 0;
}
