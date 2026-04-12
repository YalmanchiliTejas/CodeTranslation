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
#define INF (1ll<<60)
int A[51],B[51];
int N,X;
int func(int sum,int K,int le){
  if(K==X) return sum;
  if(A[le]+K<X){
    return func(sum+B[le]+1,K+A[le]+1,le);
  }
  else if(A[le]+K==X) return sum+B[le];
  else return func(sum,K+1,le-1);
}
signed main(){
  cin>>N>>X;
  A[0]=B[0]=1;
  REP(i,1,50){
    A[i]=A[i-1]*2+3;
    B[i]=B[i-1]*2+1;
  }
  cout<<func(0,0,N)<<endl;
  }

