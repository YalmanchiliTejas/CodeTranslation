#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define All(x) (x).begin(),(x).end()
using namespace std;
using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
int BinarySearch(int key,int n,int S[]){
  int l=0,r=n;
  while(r-l>1){
    int mid=(l+r)/2;
    if(S[mid]>key)r=mid;
    else l=mid;
  }
  return S[l]==(key?1:0);
}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

ll row[107],col[107];

int main() {
  ll H,W;cin >> H >> W;
  char A[107][107];
  rep(i,H){
    rep(j,W){
      cin >> A[i][j];
      if(A[i][j]=='#'){
        row[i]++;
        col[j]++;
      }
    }
  }
  rep(i,H){
    if(row[i]>0){
      rep(j,W){
        if(col[j]>0){
          cout << A[i][j];
        }
      }
      cout << endl;
    }
  }
}