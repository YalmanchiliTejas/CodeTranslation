#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<int> H(N);
    for(int i=0; i<N; i++){
        cin>>H[i];
    }

    int ans = 1;
    int h = H[0];
    for(int i=1; i<N; i++){
        if(h<=H[i]){
            ans++;
            h = H[i];
        }
    }
    cout<< ans <<endl;
    return 0;
}
