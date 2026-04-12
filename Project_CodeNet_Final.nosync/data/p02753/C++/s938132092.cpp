#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(long long i=0; i<x;i++)
#define mod 1000000007
#define INF 10000000000000000
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


struct UnionFind {
	vector<int> par;
  
  UnionFind(int N): par(N){
  	for(int i=0;i<N;i++) par[i] =i;
  }
  
  
};



int main(){
  ios::sync_with_stdio(false);
  
  string S;
  cin>>S;
  if(S[0]==S[1] && S[1] == S[2]){
  	cout<<"No";
  }else{
  	cout<<"Yes";
  }
  
}