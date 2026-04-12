#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char> (w,'-'));
    int sh = 0;
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                sh++;
            }
        }
    }
    if(sh==h+w-1){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }
}