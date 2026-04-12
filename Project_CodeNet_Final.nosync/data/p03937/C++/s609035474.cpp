#include<bits/stdc++.h>
#define rep(i,l,r) for(int (i)=(l);(i)<(r);(i)++)
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<string> a(h);
    int now=0;
    rep(i,0,h){
        cin>>a[i];
        rep(j,now,w){
            if(a[i][j]=='.')break;
            a[i][j]='.';
            now++;
        }
        now--;
    }
    int ok=1;
    if(now==w-1){
        rep(i,0,h){
          rep(k,0,w) if(a[i][k]=='#')ok=0;
        }
    }
    else ok=0;
    if(ok)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}