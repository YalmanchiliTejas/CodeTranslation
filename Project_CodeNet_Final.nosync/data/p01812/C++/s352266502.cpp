#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}

int main(void){
	cin.tie(0);ios::sync_with_stdio(false);
	int i,j,n,m,K;cin>>n>>m>>K;
	int gya[100]={0};
	int dark[16]={0};
	int road[100][100]={0};
	for(i=0;i<n;i++){gya[i]=-1;}
	for(i=0;i<m;i++){
		int d;cin>>d;d--;
		gya[d]=i;
		dark[i]=d;
	}
	static int dis[65536];
	for(int bi=0;bi<(1<<m);bi++){dis[bi]=99999;}
	dis[(1<<m)-1]=0;
	queue<int>que;que.push((1<<m)-1);
	for(i=0;i<n;i++){
		for(j=0;j<K;j++){
			cin>>road[i][j];road[i][j]--;
		}
	}
	while(que.size()){
		int pta=que.front();que.pop();
		int time=dis[pta];
		//cerr<<pta<<" "<<time<<endl;
		for(j=0;j<K;j++){
			int aaa=0;
			for(i=0;i<m;i++){
				if(!(pta&(1<<i))){continue;}
				int t=dark[i];
				if(gya[road[t][j]]<0){continue;}
				aaa|=(1<<gya[road[t][j]]);
			}
			if(mineq(dis[aaa],time+1)){que.push(aaa);}
		}
	}
	cout<<dis[0]<<endl;
	return 0;
}

