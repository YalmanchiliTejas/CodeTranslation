#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main(){
    int N;
    cin>>N;
    int m=0;
    int ans=0;
    for(int i=0;i<N;i++){
        int H;
        cin>>H;
        if(m<=H)ans++;
        m=max(m,H);
    }
    cout<<ans<<endl;
    return 0;
}