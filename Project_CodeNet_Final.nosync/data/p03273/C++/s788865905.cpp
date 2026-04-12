#include <bits/stdc++.h>
#include<algorithm>
#include<deque>
#include<string>
using namespace std;

#include<cstdio>
#define r(i,n) for(int i=0;i<n;i++)
#define N 110

int main(void){
  int n,m;
  cin>>n>>m;

  vector<vector<char> > a(N, vector<char>(N));
  vector<vector<int> > s(N, vector<int>(N,0));

  r(i,n){
    r(j,m){
      cin>>a.at(i).at(j);
    }
  }



  r(i,n){
    bool flag=1;
    r(j,m){
      if(a.at(i).at(j)=='#')flag=0;
    }
    if(flag){
        r(j,m){
          s.at(i).at(j)=1;
        }
    }
  }


  r(j,m){
    bool flag=1;
    r(i,n){
      if(a.at(i).at(j)=='#')flag=0;
    }
      if(flag){
          r(i,n){
            s.at(i).at(j)=1;
          }
      }
  }

  r(i,n){
    r(j,m){
      if(s.at(i).at(j)==0)cout<<a.at(i).at(j);
    }
    cout<<endl;
  }

return 0;}
