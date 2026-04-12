#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(){
  vector<vector<int>> s;
  int n[100]={};
  int ma[100]={};
  vector<int> mi(100,1000);
  int tmp,c = 0;
  for(int i=0;i<100;i++){
    cin >> n[i];
    if(!n[i])break;
    s.push_back(vector<int>());

    for(int j=0;j<n[i];j++){
      cin >> tmp;
      s[i].push_back(tmp);
      ma[i] = max(ma[i],tmp);
      mi[i] = min(mi[i],tmp);
    }
    c++;
  }
  int ans;
  for(int i=0;i<c;i++){
    ans = floor((accumulate(s[i].begin(),s[i].end(),0) - ma[i] - mi[i])/(s[i].size()-2));
    cout << ans << endl;
  }


  return 0;
}