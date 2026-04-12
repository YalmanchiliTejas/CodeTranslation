#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector <int>H(N);
    for(int i = 0 ; i < N ; i++){
        cin>>H[i];
    }
    
    int ans = 1;
    int top = H[0];
    for(int i = 1 ; i < N ; i++) {
        if(H[i-1] <= H[i] && top <= H[i] ) {
            ans++;
            top = H[i];
        }
    }

    cout<<ans<<endl;

    return 0;
}
