#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,h;
    cin>>N;
    vector<int> H;
    for(int i=0;i<N;i++){
        cin>>h;
        H.push_back(h);
    }
    int Max=0,ans=0;
    for(int i=0;i<N;i++){
        if(H[i]>=H[Max]){
            ans++;
            Max=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}