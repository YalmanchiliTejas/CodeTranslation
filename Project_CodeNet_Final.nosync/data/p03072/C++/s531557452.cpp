#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    int H[N];
    int hei = 0;
    int ans = 0;
    for(int i=0; i<N; i++){
        int h;
        cin>>h;
        if(h >= hei){
            ans++;
            hei = h;
        }
    }

    cout << ans << endl;
}