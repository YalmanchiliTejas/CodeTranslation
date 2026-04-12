///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//                       _oo0oo_                         //
//                      o8888888o                        //
//                      88" . "88      ------ hzt1       //
//                      (| -_- |)                        //
//                      0\  =  /0                        //
//                    ___/`---'\___                      //
//                  .' \|     |// '.                     //
//                 / \|||  :  |||// \                    //
//                / _||||| -:- |||||- \                  //
//               |   | \  -  /// |     |                 //
//               | \_|  ''\---/''  |_/ |                 //
//               \  .-\__  '-'  ___/-. /                 //
//             ___'. .'  /--.--\  `. .'___               //
//          ."" '<  `.___\_<|>_/___.' >' "".             //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |           //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /           //
//     =====`-.____`.___ \_____/___.-`___.-'=====        //
//                       `=---='                         //
//                                                       //
//                                                       //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       //
//                                                       //
//                 God-He Bless All.                     //
//           This Code Will Never Explode.               //
//                                                       //
//                                                       //
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#include<cstdio>
#include<cstring>
#include<queue>
#include<cctype>
#include<algorithm>
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
const int Size=1<<16;
char buffer[Size],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,Size,stdin);
        tail=(head=buffer)+l;
    }
    if(head==tail) return -1;
    return *head++;
}
inline int read() {
    int x=0,f=1;char c=Getchar();
    for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
    return x*f;
}
typedef pair<int,int> pr;
typedef long long ll;
const int maxn=200010;
const ll inf=1ll<<60;
#define mp make_pair
#define xx first
#define yy second
struct Heap {
	priority_queue<int> Q,del;
	int size() {return Q.size()-del.size();}
	void pop(int v) {del.push(-v);}
	void push(int v) {Q.push(-v);}
	int top() {
		while(del.size()&&Q.top()==del.top()) Q.pop(),del.pop();
		return -Q.top();
	}
}Q;
int n;
pr A[maxn],P[2*maxn];
ll solve1(int pmin,int pmax) {
	int ans=2e9,m=0;
	rep(i,1,n) if(i!=pmin&&i!=pmax) {
		P[++m]=mp(A[i].xx,0);
		P[++m]=mp(A[i].yy,i);
	}
	sort(P+1,P+m+1);
	int cl=min(A[pmin].yy,A[pmax].xx),cr=max(A[pmin].yy,A[pmax].xx);
	if(!m) ans=cr-cl;
	rep(i,1,m) {
		if(!P[i].yy) {
			Q.push(P[i].xx);
		}
		else {
			Q.pop(A[P[i].yy].xx);
			Q.push(P[i].xx);
		}
		if(Q.size()==n-2) {
			int l=min(Q.top(),cl),r=max(P[i].xx,cr);
			ans=min(ans,r-l);
		}
	}
	return (ll)ans*(A[pmax].yy-A[pmin].xx);
}
ll solve2(int pmin,int pmax) {
	int l1=A[pmin].xx,r1=A[pmax].xx,l2=A[pmin].yy,r2=A[pmax].yy;
	rep(i,1,n) if(i!=pmin&&i!=pmax) {
		r1=max(r1,A[i].xx);
		l2=min(l2,A[i].yy);
	}
	return (ll)(r1-l1)*(r2-l2);
}
int main() {
	n=read();
	rep(i,1,n) {
		int a=read(),b=read();
		if(a>b) swap(a,b);
		A[i]=mp(a,b);
	}
	if(n==1) {puts("0");return 0;}
	int pmin=1,pmax=1;
	rep(i,2,n) {
		if(A[i].xx<A[pmin].xx) pmin=i;
		if(A[i].yy>=A[pmax].yy) pmax=i;
	}
	ll ans=inf;
	ans=min(ans,solve2(pmin,pmax));
	if(pmin!=pmax) ans=min(ans,solve1(pmin,pmax));
	printf("%lld\n",ans);
	return 0;
}
