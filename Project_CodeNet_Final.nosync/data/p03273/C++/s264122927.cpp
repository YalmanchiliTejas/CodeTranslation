#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define INF 1000000000000


signed main()
 {
    int h,w;
    cin>>h>>w;
    char a[h][w];
    rep(i,h){
      rep(j,w){
        cin>>a[i][j];
      }
    }

    vector<int>safegyou(h);
    vector<int>saferetsu(w);
    rep(i,h){
      rep(j,w){
        if(a[i][j]=='#'){
          safegyou.at(i)=1;
          saferetsu.at(j)=1;
        }
      }
    }
    rep(i,h){
      rep(j,w){
        if(safegyou[i]&&saferetsu[j]){
        cout<<a[i][j];
      }
      }
      if(safegyou[i]){
        cout<<endl;
}
    }
 }
