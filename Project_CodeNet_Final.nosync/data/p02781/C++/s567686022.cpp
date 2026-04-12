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
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
signed main(){
  string S; int K; cin>>S>>K;
  int ans=0;
  if(S.size()<K)
    ans=0;
  else{
  if(K==1){
    ans=9*(S.size()-1)+S[0]-'0';
  }
  else if(K==2){
    ans=(S[0]-'1')*9*(S.size()-1);
    bool flag=1;
    rep(i,1,S.size()){
      if(flag){
        if(S[i]!='0'){
          flag=0;
          ans+=S[i]-'0';
        }
      }
      else
        ans+=9;
    }
    ans+=(S.size()-1)*(S.size()-2)/2*9*9;
  }
  else{
    ans=(S[0]-'1')*9*9*(S.size()-1)*(S.size()-2)/2;
    bool flag=1;
    rep(i,1,S.size()-1){
      if(flag){
        if(S[i]!='0'){
          flag=0;
          bool flag2=1;
          rep(j,i+1,S.size()){
            ans+=(S[i]-'1')*9;
            if(flag2){
              if(S[j]!='0'){
                flag2=0;
                ans+=S[j]-'0';
              }
            }
            else{
              ans+=9;
            }
          }
        }
      }
      else{
        rep(j,i+1,S.size())
          ans+=9*9;
      }
    }
    ans+=(S.size()-1)*(S.size()-2)*(S.size()-3)/6*9*9*9;
  }
  }
  cout<<ans<<endl;
  }

