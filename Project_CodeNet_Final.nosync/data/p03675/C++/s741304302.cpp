#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main(){
  int n;
  deque<int> data;

  cin>>n;

  for(int i=0;i<n;i++){
    int ai;
    cin>>ai;
    if((i%2)==0)
      data.push_back(ai);
    else
      data.push_front(ai);

  }
  vector<int> ans;
  if((n%2)==0){
    while(!data.empty()){
      ans.push_back(data.front());
      data.pop_front();
    }
  } else {
    while(!data.empty()){
      ans.push_back(data.back());
      data.pop_back();
    }
  }
  for(int i=0;i<ans.size();i++){
    if(i!=0)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
