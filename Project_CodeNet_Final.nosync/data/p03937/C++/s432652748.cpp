#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin>>h>>w;
    string a[h];
    for(int i = 0;i < h;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(a[i][j] == '#'){
                ans += 1;
            }
        }
    }
    if(ans == h+w-1){
        cout<<"Possible"<<endl;
    } else {
        cout<<"Impossible"<<endl;
    }
}
