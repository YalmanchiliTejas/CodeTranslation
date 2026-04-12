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
	int i,j,n,m,K,a;cin>>n;
	vector<pair<int,int>>sta(n);
	for(i=0;i<n;i++){cin>>sta[i].fir>>sta[i].sec;}
	static int dis[65536];
	for(int bi=0;bi<(1<<16);bi++){dis[bi]=99999;}
	
	vector<int>sp;
	for(j=0;j<n;j++){
		int h=sta[j].fir,w=sta[j].sec;
		for(int y=-h+1;y<=3;y++){
			for(int x=-w+1;x<=3;x++){
				int aaa=0;
				for(int ny=y;ny<y+h;ny++){
					for(int nx=x;nx<x+w;nx++){
						if(ny<0||nx<0||ny>=4||nx>=4){continue;}
						aaa|=(1<<(ny*4+nx));
					}
				}
				sp.pub(aaa);
			}
		}
	}
	SO(sp);
	sp.erase(unique(sp.begin(),sp.end()),sp.end());
	string kan[4];cin>>kan[0]>>kan[1]>>kan[2]>>kan[3];
	int R=0,B=0,G=0;
	for(int y=0;y<4;y++){
		for(int x=0;x<4;x++){
			if(kan[y][x]=='R'){R+=1<<(y*4+x);}
			if(kan[y][x]=='B'){B+=1<<(y*4+x);}
			if(kan[y][x]=='G'){G+=1<<(y*4+x);}
		}
	}
	dis[0]=0;
	queue<int>que;que.push(0);
	
	int full=65535;
	while(que.size()){
		int now=que.front();que.pop();
		int time=dis[now];
		//cerr<<pta<<" "<<time<<endl;
		for(int pta:sp){
			//ptaが押すパターン
			a=(now&(~pta))|(R&pta);
			if(mineq(dis[a],time+1)){que.push(a);}
			a=(now&(~pta))|(G&pta);
			if(mineq(dis[a],time+1)){que.push(a);}
			a=(now&(~pta))|(B&pta);
			if(mineq(dis[a],time+1)){que.push(a);}
		}
	}
	cout<<dis[65535]<<endl;
	return 0;
}

