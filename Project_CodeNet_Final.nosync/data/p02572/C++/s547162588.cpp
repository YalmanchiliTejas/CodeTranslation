#include <bits/stdc++.h>
using namespace std;

int main() {
#define rrep(i, n) for(int i = 1; i <= (int)(n); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
  int64_t N;
  cin>>N;
  int64_t sum=0;
  int64_t sqsum=0;
  int64_t answer=0;
  vector<int64_t> c(N);
  rep(i,N){
    cin>>c[i];
    sum+=c[i];
    sqsum+=c[i]*c[i];
    sum=sum%2000000014;
    sqsum=sqsum%2000000014;
  }
  sum=sum*sum;
  sum=sum%2000000014;
  answer=(sum-sqsum)%2000000014;
  answer=answer/2;
  answer=answer%1000000007;
  if(answer<0)
    answer=answer+1000000007;
  cout<<answer;
}