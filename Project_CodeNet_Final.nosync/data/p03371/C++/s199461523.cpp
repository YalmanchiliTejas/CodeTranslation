 long long A,B,C,D,E,F,    I,J,K,  M,N,O,Q,R,S,T,U,V,  X,Y,Z;
//long long A,B,C,D,E,F,  H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
double dA,dB,dC,dD,dE,dF,   dI,dJ,dK,  dM,dN,dO,dP,dQ,dR,dS,dT,dU,dV,  dX,dY,dZ;
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

typedef pair<long long,long long> P;
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
#define popcount __builtin_popcount

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

double dsum,dsum1,dsum2,dsum3,dsum4;
double dcnt,dcnt1,dcnt2,dcnt3,dcnt4;
double dwk,dwk1,dwk2,dwk3,dwk4;
double dans;
double dmax,dmax1;
double dmin,dmin1;



//bool f;

long long weight[110], value[110]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に
//ll a[100010][3]; // a[i], b[i], c[i] をそれぞれまとめて a[i][0], a[i][1], a[i][2] にしてしまう
long long n,h[100005];
vector<long long> p, c;
int vis[200001];

vector<string> fi;
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

long long match[10] = {2,5,5,4,5,6,3,7,6};
vector<long long> box;

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

// 約数列挙
vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


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

	dsum=dsum1=dsum2=dsum3=dsum4=0;
	dcnt=dcnt1=dcnt2=dcnt3=dcnt4=0;
	dmax=dmax1=0;
	dwk=dwk1=dwk2=dwk3=dwk4=0;
	dans=0;
	dmin=dmin1=INF;
	
	//std::cin >> N;
	//std::cin >> N >> M >> X;
	//std::cin >> N >> M >> K;
	//std::cin >> dB >> dA;
	//std::cin >> A >> B;
	//std::cin >> A >> B >> C;
    //cin >> K;

	
	
	//**************************こどふぉ用******************************************
	
	//char c[3]={'R', 'G', 'B'};
	//scanf("%lld:%lld",&a,&b);

	//for(int i=0,j=1;i<n;i+=j,j++)
	/*
	cin >> T;
	while(T--){
		cin >> N >> K;
		std::vector<long long> v(N);	
		// 配列入力1
		/*
		for(long long i=0; i<N; i++){
			std::cin >> v[i];
		}
		*/
		//cout << sum << '\n';
		//文字列の出力
    	//std::cout << s << std::endl;
	//}
	//re 0;
	
		//std::sort(v.begin(),v.end());//昇順ソート
		//std::sort(v.begin(),v.end(),std::greater<long long>());//降順ソート
		
		//vector<ll> v(N, 0);
		
		//map<std::string, int> freq;
		
		//マップ
		/*
		map<long long,long long> numsx;
		map<long long,long long> numsy;
		//M.clear();
		
		for(long long i=0; i<M; i++){
			wk=w[i]%K;
			numsx[wk]++;
		}
		*/
		//マップ②
		/*
		map<string, int> mp;
   	 	for(int i=0; i<n; i++){
   	    	string s; cin>>s; mp[s]++;
   		}
    	int mx=-1;
    	for(auto p:mp) mx=MAX(mx, p.second);
    	for(auto p:mp){
       		if(mx==p.second){
        		cout<<p.first<<endl;
        	}
 		}
		*/
		
		//セット
		/*
		set<long long> st;

		if(st.find(v[i])==st.end()){
			st.insert(v[i]);
		}
		else{
			st.erase(v[i]);
		}
		*/
		
		// ペア
		/*
		vector<pair<long long, long long> > p(N);
		for(long long i=0; i<N; i++){
			long long a, b;
			cin >> a >> b;
			p[i] = make_pair(a, b);
		}
		//sort(p.begin(), p.end());
		//sort(p.begin(), p.end(),greater<pair<long long,long long> >());
		*/
		//int ret=1<<20;

		//cout << sum << '\n';
		//文字列の出力
 	   //std::cout << s << std::endl;
		
	//}
	//re 0;

	//**************************ここからスタート******************************************
	//std::cin >> N;
	//std::cin >> N >> M >> X;
	//std::cin >> N >> M >> K;
	//std::cin >> dB >> dA;
	std::cin >> A >> B >> C >> X >> Y;
	if(X>Y){

		wk=MIN(A,2*C);
		pr("%lld",(ll)MIN(A*X+B*Y,Y*2*C+(X-Y)*wk));
	
	}
	else{
		wk=MIN(B,2*C);
		pr("%lld",(ll)MIN(A*X+B*Y,X*2*C+(Y-X)*wk));
	}
	//std::cin >> A >> B >> C;
    //cin >> K;
	
	//std::vector<long long> v(N);
	//std::vector<long long> w(N);
	//std::vector<long long> x(N);
	//std::vector<int> v(100, 0);
	//int a[26]={0};
	//vector<long long> flagment(N, 0);
	
	//cout << sum << '\n';

	if(1){
		//pr("%lld\n",N);
    	//printf("%lld",(ll)ceil(dB/dA));
    	//puts("Yes");
    	//printf("%d",st.size());
    	//文字列の出力
    	//std::cout << s << std::endl;
    	//printf("%.12f\n",ret);
    	//cout << sum << endl;
		//cout << sum << '\n';
		//cout << x[i] << " "  ;
		//cout << '\n';
		//pr("%02lld:%02lld",wk/60,wk%60);
	
	}
	else{
		//puts("No");
	}



	//v.push_back(i);
	//accumulate(vec.begin(), vec.end(), 0)
    
    // 配列入力1
	/*
	for(long long i=0; i<N; i++){
		std::cin >> v[i];
	}
	*/
	//std::sort(v.begin(),v.end());//昇順ソート
	//std::sort(v.begin(),v.end(),std::greater<long long>());//降順ソート
	//v.erase(unique(v.begin(), v.end()), v.end());	
	//reverse(t.begin(),t.end());

	//素因数分解
	/*
	auto pf = prime_factorize(v[i]);
	
	if(pf[0].fi==2){
		sum+=pf[0].se;
	}
	*/
	//約数列挙
	/*
	vector<long long> div = calc_divisor(M);
    
    // M の約数 d であって、d * N <= M となる最大の d を求める
    long long res = 1;
    for (auto d : div) {
        if (d * N <= M) res = max(res, d);
    }
	*/
	//素数判定
	/*
	for(int i=x; ; i++){
		bool dame=0;
		for(int j=2; j*j<=i; j++){
			if(i%j==0){
				dame=1;
				break;
			}
		}
		if(!dame){
			cout<<i<<endl;
			return 0;
		}
	}
	*/

	//文字列の出力
    //std::cout << s << std::endl;
	
	//cout << sum << '\n';

	//cout << sum << '\n';

	//ペア
	/*
	vector<pair<long long, long long> > p(N);
	for(long long i=0; i<N; i++){
		long long a, b;
		cin >> a >> b;
		p[i] = make_pair(a, b);
	}
	//sort(p.begin(), p.end());
	//sort(p.begin(), p.end(),greater<pair<long long,long long> >());
	*/

	//マップ
	/*
	map<long long,long long> numsx;
	map<long long,long long> numsy;
	//M.clear();
		
	for(long long i=0; i<M; i++){
		wk=w[i]%K;
		numsx[wk]++;
	}
	*/
	
	//マップ②
	/*
	map<string, int> mp;
    for(int i=0; i<n; i++){
        string s; cin>>s; mp[s]++;
    }
    int mx=-1;
    for(auto p:mp) mx=MAX(mx, p.second);
    for(auto p:mp){
        if(mx==p.second){
            cout<<p.first<<endl;
        }
    }
	*/

	//セット
	/*
	set<long long> st;

	if(st.find(v[i])==st.end()){
		st.insert(v[i]);
	}
	else{
		st.erase(v[i]);
	}
	*/

	

	//if(ceil(sqrt(wk)==floor(sqrt(wk))))
	//do{
	//}while(next_permutation(v.begin(),v.end()));
	
	//std::cin >> N;
	//std::cin >> N >> M >> X;
	//std::cin >> N >> M >> K;
	//std::cin >> dB >> dA;
	//std::cin >> A >> B;
	//std::cin >> A >> B >> C;
    //cin >> K;

	if(1){
		//pr("%lld\n",N);
    	//printf("%lld",(ll)ceil(dB/dA));
    	//puts("Yes");
    	//printf("%d",st.size());
    	//文字列の出力
    	//std::cout << s << std::endl;
    	//printf("%.12f\n",ret);
    	//cout << sum << endl;
		//cout << sum << '\n';
		//cout << x[i] << " "  ;
		//cout << '\n';
		//pr("%02lld:%02lld",wk/60,wk%60);
	
	}
	else{
		//puts("No");
	}
	return 0;

	
}
