#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define str string
#define rep(x,y) for(int i=x;i<y;i++)
#define REP(x,y) for(int j=x;j<y;j++)
#define all(x) x.begin(),x.end()
int main(){
  int A,C,count=1;
  cin>>A;
  vector<int> v(A);
  C=v.at(0);
  rep(0,A)cin>>v.at(i);
  rep(1,A){
    if(v.at(i)>=v.at(0)&&v.at(i)>=C){
      count+=1;
    }
    if(v.at(i)>=C)C=v.at(i);
  }
  cout<<count<<endl;
}
