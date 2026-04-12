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
#define ALL(v)  (v).begin(),(v).end()

    /*  ペア関連
    //vector<pair<long long, long long> > pairs(N);
    for(long long i=0; i<N; i++){
        long long a, b;
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }
    
    //sort(pairs.begin(), pairs.end(),greater<pair<int,int> >());
	sort(pairs.begin(), pairs.end());
    */

 	//stack<int> sta;   
    //queue<int> que;


int main(){
	int N,M,K;
	std::cin >> N;
    
	string s;
    
	
	//std::vector<long long> v(N);
	
    //std::cin >> N >> M;
    //std::cin >> N >> M >> K;
    std::cin >> s;
    std::cin >> K;
    
    //ソート
    //std::sort(v.begin(),v.end());//昇順ソート
    //std::sort(v.begin(),v.end(),std::greater<long long>());//降順ソート
    
    // 配列入力
    /*
    for(long long i=0; i<N; i++){
		std::cin >> v[i];
	}
	*/
	
	//文字列入力
	
	for(long long i=0; i<N; i++){
		
		if(s[K-1]!=s[i]){
			s[i]='*';
		}
	}
	
    if(1){
		//for(long long i=0; i<N; i++){
    	//printf("%s",s);
    	std::cout << s << std::endl;

    	//}
	}
	else{
		
	}
	return 0;
}