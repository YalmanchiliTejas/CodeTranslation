#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100
#define INF 800000000

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  vector<int> max_num;
  max_num.push_back(A.at(0));
  for(int i=1;i<N;i++){
    int k=lower_bound(max_num.begin(),max_num.end(),A.at(i))-max_num.begin();
    if(k==0){
      max_num.insert(max_num.begin(),A.at(i));
    }else{
      max_num.at(k-1)=A.at(i);
    }
  }
  cout<<max_num.size()<<endl;
}
