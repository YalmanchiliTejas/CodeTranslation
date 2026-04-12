#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    vector<pair<int,char> > shop(5);
    shop[0] = make_pair(n+m,'A');
    cin >>n>>m; shop[1] = make_pair(n+m,'B');
    cin >>n>>m; shop[2] = make_pair(n+m,'C');
    cin >>n>>m; shop[3] = make_pair(n+m,'D');
    cin >>n>>m; shop[4] = make_pair(n+m,'E');
    sort(shop.begin(),shop.end());
    cout <<shop[4].second<<" "<<shop[4].first<<endl;
  }
  return 0;
}