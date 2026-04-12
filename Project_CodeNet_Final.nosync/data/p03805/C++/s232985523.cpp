#include <bits/stdc++.h>
using namespace std;
#define rep(i,c,n) for(int i=c;i<n;i++)
 
int main() {
  int n,m,ans=0;
  cin>>n>>m;
  
  vector<pair<int,int>> p;
  rep(i,0,m){
    int tmp1,tmp2;
    cin>>tmp1>>tmp2;
    p.emplace_back(make_pair(tmp1,tmp2));
  }
  
  vector<int> per;
  rep(i,1,n+1){per.emplace_back(i);}
  
  do{
    if(per[0]!=1){break;}
    bool empty=true;
    //rep(i,0,n){cout<<per[i];}
      rep(i,0,n-1){
        bool chk=false;
        rep(j,0,m){
          if((per[i]==p[j].first&&per[i+1]==p[j].second)||(per[i+1]==p[j].first&&per[i]==p[j].second)){
            chk=true;continue;
          }
        }
        if(chk==false){empty=false;}
      }
    if(empty==true){ans++;}
      //cout<<per[i];}
    //cout<<endl;
  }while(next_permutation(per.begin(),per.end()));

  cout<<ans<<endl;
  
  return 0;
}