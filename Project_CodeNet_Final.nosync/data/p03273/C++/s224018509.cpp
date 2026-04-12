  long long A,B,C,D,E,F,  H,I,J,K,  M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
//long long A,B,C,D,E,F,  H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
double dA,dB,dC,dD,dE,dF, dH,dI,dJ,dK,  dM,dN,dO,dP,dQ,dR,dS,dT,dU,dV,  dX,dY,dZ;
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <cmath>

//typedef pair<long long,long long> P;
//typedef pair<long long,P> P1;
//typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
//#define INF 100000000000000000//19桁
#define INF 1e18+5//19桁
#define mod 1000000007
#define fi first
#define se second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define REP(i,n,x) for(long long i=n;i<x;i++)
#define REPN(i,n,x) for(long long i=n+1;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define rrep(i,x) for(long long i=x-1;i>=0;i--)
#define rrepn(i,x) for(long long i=x;i>1;i--)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()

#define ALL(v)  (v).begin(),(v).end()
//#define MAX(a,b) if(a>b)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))


const string MINUSINF = "-";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define pr printf
#define re return
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)


int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

stack<long long> sta;   
queue<long long> que;
deque<long long> dque;

set <string> s_set;




long long sum,sum1,sum2,sum3,sum4;
long long flg,flg1,flg2,flg3,cnt,cnt1,cnt2,cnt3,cnt4;
long long wk,wk1,wk2,wk3,wk4;
long long ans;

bool f;

long long weight[110], value[110]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に
ll a[100010][3]; // a[i], b[i], c[i] をそれぞれまとめて a[i][0], a[i][1], a[i][2] にしてしまう
long long n,h[100005];
vector<long long> p, c;
int vis[200001];

vector<string> fi;
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

long long match[10] = {2,5,5,4,5,6,3,7,6};
vector<long long> box;








int main(){
	
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	long long max,max1;
	long long min,min1;

	sum=sum1=sum2=sum3=sum4=0;
	flg=flg1=flg2=flg3=cnt=cnt1=cnt2=cnt3=cnt4=0;
	max=max1=0;
	wk=wk1=wk2=wk3=wk4=0;
	ans=0;
	min=min1=INF;

	
	
	//**************************こどふぉ用******************************************
	/*
	std::vector<long long> v(100005);
	cin >> T;
	while(T--){
		cin >> N >> K;
		vector<ll> last(N + 1, -INF);
		map<int,int> M;
		//M.clear();

		int ret=1<<20;

		for(int i=1;i<=N;i++){
			
		}
		cout << N << "\n";
	}
	*/
	
	//**************************ここからスタート******************************************
	std::cin >> H >> W;
	//std::cin >> X >> Y;
	//std::cin >> dT >> dA;
	//std::cin >> N >> M >> K;
	//std::cin >> N >> K;
	//std::cin >> A >> B;
	//std::cin >> A >> B >> C;
    
	//std::vector<long long> x(N);
	//std::vector<int> v(100, 0);
	//int a[26]={0};
	//vector<long long> flagment(N, 0);
	
	//vec.push_back(i);
	//accumulate(vec.begin(), vec.end(), 0)
    //v.resize
    
	// 配列入力1
	char v[H][W];
	ll w[H];
	ll x[W];
	
	rep(i,H){
		rep(j,W){
			cin >> v[i][j];
		}
	}
	
	rep(i,H){
		rep(j,W){
			if(v[i][j]!='.'){
				break;
			}
			if(j==W-1){
				h[i]=1;
			}
		}
	}
	rep(j,W){
		rep(i,H){
			if(v[i][j]!='.'){
				break;
			}
			if(i==H-1){
				w[j]=1;
			}
		}
	}
	
	rep(i,H){
		rep(j,W){
			if(w[j]==1 || h[i]==1)continue;
			pr("%c",v[i][j]);
			cnt++;
		}
		if(cnt!=0){
			pr("\n");
		}
		cnt=0;
	}
	
	re 0;
}
