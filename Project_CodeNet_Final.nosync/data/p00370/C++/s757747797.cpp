
#include <bits/stdc++.h>
using namespace std;

#define DBG(x) ;//cerr<<#x<<"="<<x<<endl;

using FLOAT = double;
const FLOAT EPS = 1e-8;
const FLOAT INF = 1e12;
typedef complex<FLOAT> P;

inline void cin_P(P&p){
	FLOAT re,im;
	cin>>re>>im;
	p=P(re,im);
}

namespace std{
	bool operator < (const P&a,const P&b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

inline bool EQ(FLOAT a,FLOAT b){return abs(a-b) < EPS;}
inline bool EQV(P a,P b){return EQ(a.real(),b.real()) && EQ(a.imag(),b.imag());}

FLOAT cross(const P&a,const P&b){
	return imag(conj(a)*b);
}

FLOAT dot(const P&a,const P&b){
	return real(conj(a)*b);
}

typedef vector<P> G;

struct L : public vector<P>{
	L(const P&a,const P&b){
		push_back(a);push_back(b);
	}
};

int ccw(P a,P b,P c){
	b-=a;c-=a;
	if(cross(b,c)>0)return +1;
	if(cross(b,c)<0)return -1;
	if(dot(b,c)<0)return +2;
	if(norm(b)<norm(c))return -2;
	return 0;
}

bool intersectSS(const L&s,const L&t){
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0 && 
	ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0;
}

G convexHull(G ps){
	int n = ps.size(),k = 0;
	assert(n >= 3);
	sort(ps.begin(),ps.end());
	G ch(2 * n);
	for(int i = 0;i < n;ch[k++] = ps[i++])
		while(k >= 2 && ccw(ch[k-2],ch[k-1],ps[i]) <= 0) --k;
	for(int i = n-2,t = k+1;i >= 0;ch[k++] = ps[i--])
		while(k >= t && ccw(ch[k-2],ch[k-1],ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}



P st,en;
int N;
G poly;

FLOAT solveConvex(){
	G conv = poly;
	conv.push_back(st);
	conv.push_back(en);
	conv = convexHull(conv);
	int si=-1,ei=-1;
	int M = conv.size();
	for(int i=0;i<M;++i){
		DBG(conv[i])
		if(EQV(conv[i],st))si=i;
		if(EQV(conv[i],en))ei=i;
	}
	assert(si>=0);assert(ei>=0);
	FLOAT one=0.0;
	for(int i=si;i!=ei;i=((i+1)%M)){
		int nx = (i+1)%M;
		one += abs(conv[i]-conv[nx]);
	}
	FLOAT two=0.0;
	for(int i=ei;i!=si;i=((i+1)%M)){
		int nx = (i+1)%M;
		two += abs(conv[i]-conv[nx]);
	}
	FLOAT res = min(one,two);
	return res;
}

FLOAT solveBinary(){
	auto score = [&](P a,P now,P b){
		return abs(a-now)+abs(now-b);
	};
	FLOAT res = INF;
	for(int i = 0;i < N;++i){
		FLOAT lo = 0.0,hi = 1.0;
		P a = poly[i];
		P b = poly[(i+1)%N];
		//a * k + b * (1-k)
		for(int loopcount=0;loopcount<30;++loopcount){
			FLOAT k1 = (lo + lo + hi) / 3;
			FLOAT k2 = (lo + hi + hi) / 3;
			P now1 = a * k1 + b * (1-k1);
			P now2 = a * k2 + b * (1-k2);
			FLOAT sc1 = score(st,now1,en);
			FLOAT sc2 = score(st,now2,en);
			DBG(now1);
			DBG(sc1);
			if(sc1<sc2){
				hi = k2;
			}else{
				lo = k1;
			}
		}
		DBG(res);
		res = min(res,score(st,a*lo+b*(1-lo),en));
	}
	return res;
}

int main(void){
	//cin >> st.real() >> st.imag();
	cin_P(st);
	cin_P(en);
	cin >> N;
	for(int i = 0;i < N;++i){
		P tmp;
		//cin >> tmp.real() >> tmp.imag();
		cin_P(tmp);
		poly.push_back(tmp);
	}
	L path(st,en);
	bool inter = false;//多角形が邪魔をしている
	for(int i = 0;i < N;++i){
		int j = (i + 1) % N;
		if(intersectSS(L(poly[i],poly[j]),path)){
			inter = true;
			break;
		}
	}
	FLOAT ans=0.0;
	DBG(inter);
	if(inter){
		ans = solveConvex();
	}else{
		ans = solveBinary();
	}
	cout.precision(15);
	cout << ans << endl;
	return 0;
}
