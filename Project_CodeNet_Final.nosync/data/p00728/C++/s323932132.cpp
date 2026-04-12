#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string.h>
using namespace std;

int main(){
  int N, i=1;
  cin >> N ;
  int v;
  vector<int> ans;
  while(N){
    vector<int> vec(N);
    for(int i = 1; i <= N;i++){
      cin >> v;
      vec[i-1] = v;
      if(i == N){
        sort(vec.begin(),vec.end());
        ans.push_back((int)(accumulate(vec.begin()+1,vec.end()-1,0)/(N-2)));
      }
    }
    cin >> N;
  }
  for(int i  =0 ; i < (int)ans.size();i++){
    cout << ans[i] << endl;
  }
}

