#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n){
        cin >> h[i];   
    }
    int count=1;
    bool ans = true;
    for(int i=1;i<n;i++){
        ans = true;
        for(int j=0;j<i;j++){
            if(h[i]<h[j]){
                ans=false;
            }
        }
        if(ans){
            count++;
        }
    }
    cout<<count<<endl;
}