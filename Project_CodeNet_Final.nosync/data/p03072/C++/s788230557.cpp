#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int H[21];

int main(){

    cin >> N;
    for(int i = 0;i < N; i++){
        cin >> H[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        bool ok = true;
        for(int j = 0; j < i; j++){
            if(H[i] < H[j]){
                ok = false;
            }
        }
        if(ok)ans++;
    }
    cout<< ans << endl;

    return 0;
}
