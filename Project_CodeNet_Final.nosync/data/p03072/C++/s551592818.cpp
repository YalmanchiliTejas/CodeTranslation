#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;++i) cin >> h[i];
    int max = 0, cnt = 0;
    for(int i=0;i<n;++i){
        if(max <= h[i]){
            ++cnt;
            max = h[i];
        }
    }
    cout << cnt << endl;
}
