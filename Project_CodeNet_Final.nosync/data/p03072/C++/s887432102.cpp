#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,h[100005];
ll dp[100005];

int main(){
	int N,M,K;
	std::cin >> N;
    //std::cin >> N >> M;
    //std::cin >> N >> M >> K;
    
    std::vector<long long> v(N+1);
 	
 	//stack<int> sta;   
    //queue<int> que;
    
 	
    // 入力
    int cnt,max;
    cnt=1;
    max=0;
    for(long long i=1; i<=N; i++){
		std::cin >> v[i];
		if(i!=1){
		if(max<=v[i]){
			cnt++;
		}
		}
		if(v[i]>=max){
			max=v[i];
		}
		
	}
    
    printf("%d",cnt);
    //printf("%d",N*M);
	return 0;
}