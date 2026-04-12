#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> P;
typedef pair<long long,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
long long n,h[100005];
ll dp[100005];
#define ALL(v)  (v).begin(),(v).end()
//#define MAX(a,b) if(a>b)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#define DEBUG
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

stack<long long> sta;   
queue<long long> que;
set <string> s_set;

int main(){
	
	long long A,B,C,D,E,F,G,H,I,J,L,N,M,K,O,P,Q,R,S,T,U,V,W,X,Y,Z;
	long long ans;
	ans=0;
	string s;
	long long sum,sum1,sum2,sum3,sum4;
	sum=0;
	sum1=0;
	sum2=0;
	sum3=0;
	sum4=0;
	long long flg,flg1,cnt,cnt1,cnt2,cnt3,cnt4;
	flg=0;
	flg1=0;
	cnt=0;
	cnt1=0;
	cnt2=0;
	cnt3=0;
	cnt4=0;
	long long max;
	long long max1;
	max=0;
	max1=0;
	long long min;
	long long min1;
	min=INF;
	min1=INF;

	long long work,work1,work2,work3,work4;
	work=0;
	work1=0;
	work2=0;
	work3=0;
	work4=0;
    
	//long long a[4];
	long long value;
	value=0;

    
	std::cin >> A >> B >> C >> X >>Y;
	//std::cin >> N >> M;
	//std::cin >> N >> M >> K;
	//std::cin >> N >> K;
    
	//std::vector<long long> v(N);
	//std::vector<long long> w(N);
	
	//vec.push_back( i );
	//accumulate(vec.begin(), vec.end(), 0)
    
	// 配列入力1
	/*
	for(long long i=0; i<N; i++){
		std::cin >> v[i];
		v[i]=abs
	}
	*/
	
	//std::sort(v.begin(),v.end());//昇順ソート
	//std::sort(v.begin(),v.end(),std::greater<long long>());//降順ソート
	
	//通常
	/*
	for(long long i=0; i<N; i++){
		
		
		#ifdef DEBUG
		//printf("%d\n",v[i]);	
		#endif
		
	}
	*/
	
	

	//文字列入力
	/*
	std::cin >> s;
	//sort(s.begin(), s.end());
	for(long long i=0; i<s.length(); i++){
		
		//work=(s[i+2]-'0')+10*(s[i+1]-'0')+100*(s[i]-'0');
		if(s[i]!='1'){
		}
		//S.substr(i, 5);
		//S.size();
	
	}
	*/
	
	// 配列入力2
	/*
	for(long long i=0; i<N; i++){
		std::cin >> w[i];
	}
	*/
	//std::sort(w.begin(),w.end());//昇順ソート
	//std::sort(w.begin(),w.end(),std::greater<long long>());//降順ソート
	
	//  ペア関連
	/*
	vector<pair<long long, long long> > pairs(N);
	for(long long i=0; i<N; i++){
		long long a, b;
		cin >> a >> b;
		pairs[i] = make_pair(a, b);
	}
    
	sort(pairs.begin(), pairs.end());
	//sort(pairs.begin(), pairs.end(),greater<pair<long long,long long> >());
	
	//通常（ペア用）
	
	for(long long i=0; i<N; i++){
		
	}
	*/

	//  set関連
	/*
	std::set<long long> st;
	for(long long i=0; i<N; i++){
		std::cin >> v[i];
		if(st.find(v[i])==st.end()){
			st.insert(v[i]);
		}
		else{
			st.erase(v[i]);
		}
	}
	*/
	// set 文字列関連
	/*
	for(long long i=0; i<S.size(); i++) {
    	s.insert(S[i]);
  	}
  	cnt=(int)s.find('a');
  	*/
	
	//	map関連
	/*
	bool ok = true;
	map<char,char> ma, ima;
	for (int i = 0; i < S.size(); ++i) {
		char s = S[i], t = T[i];
		if (ma.count(s)) if (ma[s] != t) ok = false;
		if (ima.count(t)) if (ima[t] != s) ok = false;
		ma[s] = t; ima[t] = s;
	}	
	*/
	
	//	pow, sqrt,整数判定関連
	/*
	work+=pow(v[j][i]-v[m][i],2);	//	workはdouble
	work=sqrt(work);				//	workはdouble
	if(ceil(work) == floor(work)){	//	整数判定
	}
	*/
	
	//	各桁の取り出し 関連
	/*	
	a[0] = (value % 10); 
	value /= 10;// 1桁目を取り出す
	a[1] = (value % 10); 
	value /= 10;// 2桁目を取り出す
	a[2] = (value % 10); 
	value /= 10;// 3桁目を取り出す
	a[3] = (value % 10); 
	value /= 10;// 4桁目を取り出す
	work1=a[0]+10*a[1];
	work2=a[2]+10*a[3];
	*/
	
	
	if(A+B>2*C){
    	work=2*C*MIN(X,Y);
    	if(X>Y){
			work=MIN(work+A*(MAX(X,Y)-MIN(X,Y)),work+2*C*(MAX(X,Y)-MIN(X,Y)));
    	}
    	else{
			work=MIN(work+B*(MAX(X,Y)-MIN(X,Y)),work+2*C*(MAX(X,Y)-MIN(X,Y)));
		}
    	printf("%lld",work);
    	//printf("%lld",N);
    	//puts("Yes");
    	//printf("%d",st.size());
    	//文字列の出力
    	//std::cout << s << std::endl;
    	//printf("%.12f\n",ret);
    	//cout << sum << endl;
	}
	else{
		printf("%lld",A*X+B*Y);
	}
	return 0;
}
