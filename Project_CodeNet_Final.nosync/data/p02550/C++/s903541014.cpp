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
  map<int,int> A,index;
  
  A[1] = X;
  index[X] = 1;
  int start,end,last;
  int cnt = 1;
  int sum = 0;
  bool loop = false;
  repeq(i,1,N-1){
    A[i+1] = A[i] * A[i] % M;
    if (index[A[i+1]] > 0){
      start = index[A[i+1]];
      end = i;
      loop = true;
      break;
    } else {
      index[A[i+1]] = i+1;
    }
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
    repeq(i,start,N - (last - start)){
      ans += A[i];
    }
  } else {
    repeq(i,1,N){
      ans += A[i];
    }
  }
  cout << ans;
}
