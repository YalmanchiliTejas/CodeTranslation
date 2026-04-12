#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  vector<int64_t>r(N),l(N);
  for(int i=0;i<N-1;i++){
    if(i%2==0){l[i+1]++;l[i]--;}
    else{l[i]++;l[i+1]--;}
  }
  for(int i=0;i<N-1;i++){
    if(i%2==0){r[i]++;r[i+1]--;}
    else{r[i]--;r[i+1]++;}
  }
  sort(l.begin(),l.end());
  sort(r.begin(),r.end());
  int64_t suml=0,sumr=0;
  for(int i=0;i<N;i++){
    suml+=(A[i]*l[i]);
    sumr+=(A[i]*r[i]);
  }
  cout<<max(suml,sumr)<<endl;
  return 0;                       
}