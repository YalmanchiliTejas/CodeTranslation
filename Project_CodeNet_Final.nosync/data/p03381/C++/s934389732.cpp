#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
  int N;
  cin>>N;
  vector<int> v,w;
  for(int i = 0;i<N;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  w=v;
  sort(v.begin(),v.end());


  for(int i = 0;i<N;i++){
    if(w[i]<=v[v.size()/2-1]){
      cout<<v[v.size()/2]<<endl;
    }else{
      cout<<v[v.size()/2-1]<<endl;
    }
  }


  return 0;
}
