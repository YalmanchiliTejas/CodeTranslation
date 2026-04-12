#include<bits/stdc++.h>
using namespace std;

int main(void){

    int N; cin>>N;
    vector<int> H(N);

    for (int i = 0; i < N; ++i) {
        cin>>H[i];
    }

    int maximum=0, ans=0;
    for (int i = 0; i < N; ++i) {
        if(maximum<=H[i]){
            maximum = H[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}