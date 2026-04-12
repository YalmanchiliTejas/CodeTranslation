#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,sum=0;
  cin>>N;
  vector<int>v(N);
  for (int i=0;i<N;i++){
    int a;
    cin>>a;
    v.at(0)=a;
    sort(v.begin(),v.end());
    if (v.at(N-1)==a){
      sum++;
    }
  }
  cout<<sum<<endl;
}
