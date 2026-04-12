#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    int a[h][w];
    rep(i,h)rep(j,w)a[i][j]=0;

    int bh[h],bw[w];
    rep(i,h)bh[i]=0;
    rep(i,w)bw[i]=0;
    
    rep(i,h){
        string s;cin>>s;
        rep(j,w)if(s[j]=='#'){
            a[i][j]=1;
            bh[i]=1;
            bw[j]=1;
        }
    }
    
    rep(i,h){
        rep(j,w){
            if(bh[i]==0||bw[j]==0)continue;
            else{
                if(a[i][j]==1)cout<<'#';
                else cout<<'.';
            }
        }
        cout<<endl;
    }
	return 0;
}