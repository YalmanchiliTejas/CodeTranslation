#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
double EPS=1e-10;
double EQ(double a,double b){
    return abs(a-b)<EPS;
}
void fast_stream(){
  std::ios_base::sync_with_stdio(0);
}

int N,M,W,T;
string ss[10];
int vs[10];
int ps[10];
int ls[10];
int xs[10];
int ys[10];
vector<pii> sels[10];
int minDists[1<<7];
// 各町の組み合わせごとに，何がいくらで買えるかをリストアップ
vector<pii> wb[1<<7];
// 今のmaskにおいて，まだWの余裕があるときに獲得できる利益の最大数
int dp1[1<<7][10][10001];
// 現在の時間からえられる最大の利益
ll dp2[10001];

const int INF=1<<30;
int main(){
  while(cin>>N>>M>>W>>T&&(N|M|W|T)){
    map<string,int> dict;
    for(int i=0;i<10;i++)sels[i].clear();
    for(int i=0;i<M;i++){
      cin>>ss[i]>>vs[i]>>ps[i];
      int idx=dict.size();
      if(dict.count(ss[i])==0)dict[ss[i]]=idx;
    }
    for(int i=0;i<N;i++){
      cin>>ls[i]>>xs[i]>>ys[i];
      for(int j=0;j<ls[i];j++){
	int r,q;
	string s;
	cin>>s>>q;
	r=dict[s];
	sels[i].push_back(pii(r,q));
      }
    }
    // 各訪れる町の組み合わせごとの最短コストを求める
    for(int mask=0;mask<(1<<N);mask++){
      vector<int> v;
      for(int j=0;j<N;j++)if((mask>>j)&1)v.push_back(j);
      minDists[mask]=INF;
      do{
	pii cur=pii(0,0);
	int sum=0;
	for(int j=0;j<(int)v.size();j++){
	  sum+=abs(cur.second-xs[v[j]])+abs(cur.first-ys[v[j]]);
	  cur=pii(ys[v[j]],xs[v[j]]);
	}
	sum+=abs(cur.first)+abs(cur.second);
	minDists[mask]=min(minDists[mask],sum);
      }while(next_permutation(v.begin(),v.end()));
    }
    // 各訪れる町ごとに，かえる商品のリストを作成し，DP
    for(int mask=0;mask<(1<<N);mask++){
      map<int,int> m;
      for(int j=0;j<N;j++){
	if((mask>>j)&1){
	  for(int k=0;k<(int)sels[j].size();k++){
	    int idx=sels[j][k].first;
	    int val=sels[j][k].second;
	    if(val<ps[idx]){
	      if(m.count(idx)==0)
		m[idx]=ps[idx]-val;
	      else
		m[idx]=max(m[idx],ps[idx]-val);
	    }
	  }
	}
      }
      for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	wb[mask].push_back(pii(it->first,it->second));
    }
    // 各訪れる町の組み合わせごとに，ある重みWにおいて，買うことのできる最大の利益を求めておく
    for(int mask=0;mask<(1<<N);mask++){
      for(int i=wb[mask].size();i>=0;i--){
	for(int j=0;j<=W;j++){
	  int res=0;
	  if(i!=(int)wb[mask].size()){
	    res=max(res,dp1[mask][i+1][j]);
	    if(j-vs[wb[mask][i].first]>=0)
	      res=max(res,dp1[mask][i][j-vs[wb[mask][i].first]]+wb[mask][i].second);
	  }
	  dp1[mask][i][j]=res;
	}
      }
    }
    // for(int i=0;i<(1<<N);i++){
    //   cout<<dp1[i][0][W]<<endl;
    // }
    // for(int mask=0;mask<(1<<N);mask++){
    //   cout<<minDists[mask]<<endl;
    // }
    //cout<<T<<endl;
    // 時間Tにおいて，どのmaskを選べば最大の利益を選べるかを行うDP
    for(int i=0;i<=T;i++){
      ll res=0;
      for(int mask=0;mask<(1<<N);mask++)
	if(i-minDists[mask]>=0)res=max(res,dp2[i-minDists[mask]]+dp1[mask][0][W]);
      dp2[i]=res;
    }
    cout<<dp2[T]<<endl;
  }
  return 0;
}