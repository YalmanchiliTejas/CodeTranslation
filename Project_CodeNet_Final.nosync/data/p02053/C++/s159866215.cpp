#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<(n);i++)
#define int long long

signed main()
{
    int H,W; cin>>H>>W;
    vector<string> s(H);
    for(int i=0;i<H;i++){
      cin>>s[i];
    }

    vector<pair<int,int>> v;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(s[i][j]=='B'){
          v.push_back(make_pair(i,j));
          break;
        }
      }
      for(int j=W-1;j>=0;j--){
        if(s[i][j]=='B'){
          v.push_back(make_pair(i,j));
          break;
        }
      }
    }

    int ans=0;
    for(auto p:v){
      for(auto q:v){
        ans=max(ans,abs(p.first-q.first)+abs(p.second-q.second));
      }
    }
    cout<<ans<<endl;
}


