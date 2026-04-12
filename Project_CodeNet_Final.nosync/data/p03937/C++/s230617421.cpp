#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,h){
        cin>>s[i];
    }
    pair<int,int>x=make_pair(0,0);
    s[0][0]='.';
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'&&((i==x.first&&j==x.second+1)||(i==x.first+1&&j==x.second))){
                s[i][j]='.';
                x=make_pair(i,j);
            }
        }
    }
    if(x!=make_pair(h-1,w-1)){cout<<"Impossible"<<endl;}
    else{
        rep(i,h){
            rep(j,w){
                if(s[i][j]=='#'){
                    cout<<"Impossible"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Possible"<<endl;
    }
}
