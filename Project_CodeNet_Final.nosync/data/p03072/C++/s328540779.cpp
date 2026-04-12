#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[N];
    int mx=0,ans=0;

    for(int i=0;i<N;i++){
        cin >> H[i];
        if(mx<=H[i]){
            mx=H[i];
            ans++;
        }
    }
    
    cout <<  ans << endl;
}