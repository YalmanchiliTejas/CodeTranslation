//Rank Checker
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int a[101];

int main(){
  int n, s;
  while(true){
    scanf("%d,%d", &n, &s);
    if(n==0 && s==0)break;
    v.push_back(make_pair(s, n));
  }
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  int t=1;
  a[v[0].second]=t;
  for(int i=1; i<v.size(); i++){
    if(v[i].first!=v[i-1].first)t++;
    a[v[i].second]=t;
  }
  while(cin>>n){
    cout<<a[n]<<endl;
  }
  return 0;
}