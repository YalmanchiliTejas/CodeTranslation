#include <bits/stdc++.h> //AtCoder
#include <iostream> //Codeforces
#include <vector> //Codeforces

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Vc vector<char>
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl

using namespace std;
/****************************** START ******************************/

signed main(){
  int N,X,M;
  cin >> N >> X >> M;
  map<int,int> A,B;
  
  A[1] = X;
  int now = X;
  int start,end,last;
  int cnt = 1;
  int sum = 0;
  bool loop = false;
  
  rep(i,0,N){
    if(B[now]!=0){
      start = B[now];
      end = i+0;
      loop = 1;
      break;
    }
    B[now] = i+1;
    now = now*now%M;
  }
  
  repeq(i,2,200000){
    /*repeq(j,1,i-1){
      if (A[j] == A[i]){
        start = j;
        end = i - 1;
        loop = true;
        break;
      } else {
        if (j == i-1){
          A[i] = A[i-1] * A[i-1] % M;
        }
      }
    }*/
    A[i] = A[i-1] * A[i-1] % M;
    /*if (loop){
      break;
    }*/
  }
  
  int ans = 0;
  if (loop){
    repeq(i,1,start - 1){
      ans += A[i];
    }
    
    repeq(i,start,end){
      sum += A[i];
    }
    cnt = (N - (start - 1))/(end - (start - 1)); 
    ans += sum * cnt;
    
    last = start + (end - (start - 1)) * cnt;
    repeq(i,last,N){
      ans += A[i- (last - start)];
    }
  } else {
    repeq(i,1,N){
      ans += A[i];
    }
  }
  cout << ans;
  
}
