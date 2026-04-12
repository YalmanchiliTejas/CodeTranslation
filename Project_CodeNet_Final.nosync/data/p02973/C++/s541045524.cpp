#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
#define mkp make_pair
typedef long long ll;
using namespace std;

int N;
vector<int> A;

bool judge(int lim){
  set<pair<int,int>> se;
  int now=0;
  for(int i=0;i<N;i++){
    auto itr=se.upper_bound(mkp(A[i],-1));
    if(itr==se.begin()){
      if(now>=lim) return false;
      se.insert(mkp(A[i],now+1));
      now++;
    }else{
      itr--;
      auto f=*itr;
      auto nex=mkp(A[i],f.second);
      se.erase(f);
      se.insert(nex);
    }
  }
  return true;
}

int main(){
  cin>>N;
  A.resize(N);
  for(int i=0;i<N;i++) cin>>A[i];

  int ok=N,ng=0;
  while(ok-ng>1){
    int mid=(ok+ng)/2;
    if(judge(mid)) ok=mid;
    else ng=mid;
  }

  cout<<ok<<endl;

  return 0;
}
