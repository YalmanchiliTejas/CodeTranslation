#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


int n,m;
vector<int> l;
bool input(){
  l.clear();
  cin>>n>>m;
  if(n==0 && m==0)return false;
  for(int i=0;i<n+m;i++){
    int tmp;
    cin>>tmp;
    l.push_back(tmp);
  }
  return true;
}

int solve(){
  l.push_back(0);
  sort(l.begin(),l.end());
  int ans = 0;
  for(int i=1;i<l.size();i++){
    ans = max(ans,abs(l[i-1]-l[i]));
  }
  return ans;
}


int main(){
  while(input()){
    cout<<solve()<<endl;
  }
}