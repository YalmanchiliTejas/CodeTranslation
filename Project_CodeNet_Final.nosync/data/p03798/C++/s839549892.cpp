#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
signed main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  string ans;
  bool flag=1;
  rep(j,0,4){
    bitset<100001> A(j);
    rep(i,0,N-1){
      if(A.test(i+1)){
        if(S[i+1]=='o'){
          if(A.test(i))
            A.set(i+2);
        }
        else{
          if(!A.test(i))
            A.set(i+2);
        }
      }
      else{
        if(S[i+1]=='o'){
          if(!A.test(i))
            A.set(i+2);
        }
        else{
          if(A.test(i))
            A.set(i+2);
        }
      }
    }
    bool F=0;
    if((A.test(0)&&A.test(N))||(!A.test(0)&&!A.test(N))){
    if(S[0]=='o'){
      if(A.test(0)){
        if(A.test(1)){
          if(A.test(N-1))
            F=1;
        }
        else{
          if(!A.test(N-1))
            F=1;
        }
      }
      else{
        if(A.test(1)){
          if(!A.test(N-1))
            F=1;
        }
        else{
          if(A.test(N-1))
            F=1;
        }
      }
    }
    else{
      if(A.test(0)){
        if(A.test(1)){
          if(!A.test(N-1))
            F=1;
        }
        else{
          if(A.test(N-1))
            F=1;
        }
      }
      else{
        if(A.test(1)){
          if(A.test(N-1))
            F=1;
        }
        else{
          if(!A.test(N-1))
            F=1;
        }
      }
    }
  }
    if(F){
      flag=0;
      rep(i,0,N){
        if(A.test(i))
          ans+='S';
        else
          ans+='W';
      }
      break;
    }
  }
  if(flag)
    ans="-1";
  cout<<ans<<endl;
  }

