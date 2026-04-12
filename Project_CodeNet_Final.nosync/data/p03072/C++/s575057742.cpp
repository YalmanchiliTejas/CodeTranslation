#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> h(N);
    for(int i=0;i<N;i++){
        cin>>h[i];
        
    }
    int max=h[0];
    int ans=0;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(max<=h[i]) {
            cnt++;
            max=h[i];
        }
        else{
            continue;
        }
        
    }
    
    cout<<cnt<<endl;
    
}
    
