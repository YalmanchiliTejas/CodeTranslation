#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  
  vector<int>x(N);//Aを小大小大...に並べた場合の係数.偶数番目は小さいので'-'
  vector<int>y(N);//   大小大小...　　　　場合の係数.         大きい　 '+'
  for(int i=0;i<N;i++){
    if(i%2!=0){if(i-1>=0){x[i]++;y[i]--;}
               if(i+1<N){x[i]++;y[i]--;}
    }
    if(i%2==0){if(i-1>=0){x[i]--;y[i]++;}
               if(i+1<N){x[i]--;y[i]++;}
    }
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  //小さい係数に小さいAを割り当てる
  int64_t sumx=0,sumy=0;
  for(int i=0;i<N;i++){
    //cout<<"x "<<x[i]<<" "<<"y "<<y[i]<<endl;
    sumx+=(x[i]*A[i]);
    sumy+=(y[i]*A[i]);
  }
  cout<<max(sumx,sumy)<<endl;
  
  return 0;
}