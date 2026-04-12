#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
using namespace std;
using Graph = vector<vector<int>>;
namespace adaptor = boost::adaptors;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl

typedef long long ll;

bool IsAdjacent(int n, int m, Graph G){
	if(n==m) {return false;}
	// v[m] の中に n がいれば true
	rep(i,G[m].size()){
  		if(G[m][i] == n) return true;
    }
  	return false;
}

void Main(){
   int N, M;
   cin >> N >> M;
  
  	// 頂点数 N, 辺数 M, 無向グラフ
  	// 
  	Graph G(N);
   	rep(i,M) {
        int a, b;
        cin >> a >> b;
     	a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
   	}
  	
  	int count = 0;
  	vector<int> v(N);
	iota(v.begin(), v.end(), 0);
	// 頂点 0 から N-1 までの全ての順列を探索
  	do{
		if(v[0] != 0){;}
      	else{
          int flag = 1;
          rep(i,N-1){
            if(!IsAdjacent(v[i], v[i+1], G)){flag = 0;}
          }
          if(flag){count++;}
        }
    }while(next_permutation(v.begin(), v.end()));

  	cout << count << endl;
	return;
 }
  
int main(){
 cin.tie(nullptr);
 ios_base::sync_with_stdio(false);
 cout << fixed << setprecision(15);
 Main();
 return 0;
 }
