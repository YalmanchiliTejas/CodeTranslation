#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9;

int N, M, W, T, v[7], p[7];

int L[7], X[7], Y[7], q[7][7];

string s[7], r[7][7];

unordered_map<string,int> num;

int dp1_0[1<<7][7];

int dp1[1<<7]; // iの町を訪れる時の最小時間

int dp2[1<<7][7]; // iの町を訪れる時のjの商品の最小価格

int dp3[10005]; // (iの町を訪れる時にj番目までで)kの重さの合計の時の最大利益

vector<int> t, S; // t_i秒消費でsum_i使える

int dp[10005]; // (上のものを使い、i番目までで)jの時間の時の最大利益

int getD(int A, int B){
  return abs( X[A] - X[B] ) + abs( Y[A] - Y[B] );
}

void DP1(){
  
  for(int i=0;i<(1<<N);i++){
    
    for(int j=0;j<N;j++) dp1_0[i][j] = INF;
    
    dp1[i] = INF;
  }
  
  for(int i=0;i<N;i++) dp1_0[1<<i][i] = abs( X[i] ) + abs( Y[i] );
  
  for(int i=0;i<(1<<N);i++){
    
    for(int j=0;j<N;j++){
      
      if( dp1_0[i][j] == INF ) continue;
      
      for(int k=0;k<N;k++){
	
	if( i>>k & 1 ) continue;
	
	int ni = i | ( 1 << k );
	
	dp1_0[ni][k] = min( dp1_0[ni][k], dp1_0[i][j] + getD( j, k ) );
	
      }
      
    }
    
  }
  
  for(int i=0;i<(1<<N);i++){
    
    for(int j=0;j<N;j++){
      
      if( dp1_0[i][j] == INF ) continue;
      
      dp1_0[i][j] += abs( X[j] ) + abs( Y[j] );
      
      dp1[i] = min( dp1[i], dp1_0[i][j] );
      
    }
    
  }
  
}

void DP2(){
  
  for(int i=0;i<(1<<N);i++)
    for(int j=0;j<M;j++) dp2[i][j] = INF;
  
  for(int i=0;i<(1<<N);i++){
    
    for(int j=0;j<N;j++){
      
      if( i >> j & 1 ){
	
	for(int k=0;k<L[j];k++){
	  
	  int idx = num[r[j][k]];
	  
	  dp2[i][idx] = min( dp2[i][idx], q[j][k] );
	  
	}
	
      }
      
    }
    
  }
  
}

void DP3(){
  
  for(int i=0;i<(1<<N);i++){
    
    memset( dp3, 0, sizeof(dp3) );
    
    int minsum = -1;
    
    for(int j=0;j<M;j++){
      
      for(int k=0;k<=W;k++){
		
	int pk = k - v[j];
	
	if( pk < 0 ) continue;
	
	dp3[k] = max( dp3[k], dp3[pk] + ( p[j] - dp2[i][j] ) );
	
	minsum = max( minsum, dp3[k] );
	
      }
      
    }
    
    if( minsum == -1 ) continue;
    
    t.push_back( dp1[i] );
    
    S.push_back( minsum );
    
  }
  
}

int DP(){
  
  int len = (int)t.size();
  
  for(int i=0;i<len;i++){
    
    for(int j=0;j<=T;j++){
      
      int pj = j - t[i];
      
      if( pj < 0 ) continue;
      
      dp[j] = max( dp[j], dp[pj] + S[i] );
      
    }
    
  }
  
  int res = 0;
  
  for(int i=0;i<=T;i++) res = max( res, dp[i] );
  
  return res;
}

signed main(){
  
  cin>>N>>M>>W>>T;
  
  for(int i=0;i<M;i++){
    cin>>s[i]>>v[i]>>p[i];
    num[s[i]] = i;
  }
  
  for(int i=0;i<N;i++){
    
    cin>>L[i]>>X[i]>>Y[i];
    
    for(int j=0;j<L[i];j++){
      
      cin>>r[i][j]>>q[i][j];
      
    }
    
  }
  
  DP1();
  
  DP2();
  
  DP3();
  
  cout<<DP()<<endl;
  
  return 0;
}

