#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin>>N;
    vector<int> H(N);
    int maximum=0;
    int count=0;
    for(int i=0;i<N;i++){
        cin>>H[i];
        if(maximum<=H[i]){
            count++;
        }
        maximum=max(maximum,H[i]);
    }
    cout<<count;
    return 0;
}