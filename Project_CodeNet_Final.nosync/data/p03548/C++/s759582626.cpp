#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;

int main(){
  int X,Y,Z;
  cin>>X>>Y>>Z;
  X-=Z;
  cout<<X/(Y+Z)<<endl;
}
