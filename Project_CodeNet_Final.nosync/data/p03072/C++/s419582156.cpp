#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> H(0,0);
    int N;
    cin >> N;
    int max=0;
    int ans=0;
    for(int i=1;i<=N;i++){
        int h;
        cin >> h;
        if(h >= max){
            max = h;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}