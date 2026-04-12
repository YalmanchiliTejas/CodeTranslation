#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  
  long long ttttt=0;
  vector<long long> A(200000);
  for(int a=0;a<N;a++){
    cin>>A.at(a);
    ttttt+=A.at(a);
  }
 // long long hozon=ttttt;
  //sort(A.begin(),A.end());
  //long long amari=0;
  long long amari=0;
 
  for(int p=0;p<N-1;p++){
    long long hozon=0;
    bool judge=0;
    ttttt-=A.at(p);
    if(ttttt>=1000000007){
      hozon=ttttt;
      ttttt=ttttt%1000000007;
      judge=1;
    }
    amari+=A.at(p)*ttttt;
    if(amari>=1000000007){
      //cout<<total<<"totalllll"<<endl;
      //amari+=total%1000000007;
      amari=amari%1000000007;
       // cout<<amari<<"amari"<<endl;
    }
    if(judge){
      ttttt=hozon;
    }
      //cout<<total<<"total"<<endl;
  }
  //  if(total>=1000000007){
 //     amari=amari%1000000007;
      
 //   }

  cout<<amari;
}


