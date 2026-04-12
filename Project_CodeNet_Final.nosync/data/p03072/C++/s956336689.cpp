#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>
#include<algorithm>
#include<complex>
#include<queue>
#include<stdlib.h>
#define ll long long

using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> H(N,0);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    int ans=1;
    int max=H[0];
    for(int i=1;i<N;i++){
        if(max<=H[i]){
            ans++;
            max=H[i];
        }
    }
    cout << ans << endl;
    return 0;
}
