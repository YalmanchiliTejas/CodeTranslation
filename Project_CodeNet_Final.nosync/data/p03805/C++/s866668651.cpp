#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int>order(N-1);
  for(int i=0;i<N-1;i++){
    order.at(i)=i+2;
  }
  vector<set<int>>data(N+1);
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    data.at(a).insert(b);
    data.at(b).insert(a);
  }
  int count=0;
  do{
    bool res=true;
    if(!data.at(1).count(order.at(0))) res=false;
    for(int i=0;i<N-2;i++){
      if(!data.at(order.at(i)).count(order.at(i+1))) res=false;
    }
    if(res) count++;
  }while(next_permutation(order.begin(),order.end()));
  cout << count;
}
