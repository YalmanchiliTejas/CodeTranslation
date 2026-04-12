#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int N, cnt=0;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++){
        cin >> H[i];
    }
    int max=H[0];
    for(int i=0; i<N; i++){
        if(H[i]>=max){
            cnt++;
            max = H[i];
        }
    }
    cout << cnt;
}