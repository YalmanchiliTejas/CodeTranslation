#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,string> Team;
main(){
  int n;
  int cnt=0;
  int kati,make,hikiwake;
  while(1){
    cin>>n;
    if(n==0)break;
    if(cnt!=0){
      cout<<endl;
    }
    Team team[100];
    for(int i=0;i<n;i++){
      cin>>team[i].second>>kati>>make>>hikiwake;
      team[i].first.first=-(kati*3+hikiwake);
      team[i].first.second=i;
    }
    sort(team,team+n);
    for(int i=0;i<n;i++){
      cout<<team[i].second<<','<<-team[i].first.first<<endl;
    }
    cnt++;
  }
}
      
    