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
using namespace std;
typedef long long int llint;
typedef long double lldo;
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
//cout<<setprecision(20)
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int LBI(vector<llint>&ar,llint in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
int UBI(vector<llint>&ar,llint in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
static int val[869120]={0};//最小値が親+何段か
static int dco[869120]={0};//最小値のうち右端はどこか
class seg{
public:
	
	//524288
	//(1<<19)+300000 以上
	//奇数場所優先
	void cha(int bas,int num){
		bas+=(1<<19);
		while(bas>1){
			if(bas%2==1){
				val[bas-1]+=num;
				int hen=min(val[bas],val[bas-1]);
				val[bas]-=hen;
				val[bas-1]-=hen;
				val[bas/2]+=hen;
				if(val[bas]==0){dco[bas/2]=dco[bas];}
				else{dco[bas/2]=dco[bas-1];}
			}else{
				int hen=min(val[bas],val[bas+1]);
				val[bas]-=hen;
				val[bas+1]-=hen;
				val[bas/2]+=hen;
				if(val[bas+1]==0){dco[bas/2]=dco[bas+1];}
				else{dco[bas/2]=dco[bas];}
			}
			bas/=2;
		}
	}
	int que(int bas){
		int ans=-2;
		bas+=(1<<19);
		while(bas>1){
			if(val[bas]>0){ans=-2;}
			if(bas%2==1){maxeq(ans,dco[bas-1]);}
			bas/=2;
		}
		return ans;
	}
};
int main(void){
	int n,Q,i;cin>>n>>Q;
	string str;cin>>str;
	//最小値右端+1
	set<int>clo;
	seg ki;
	for(i=0;i<n;i++){
		dco[(i+1)/2+(1<<19)]=i+1;
		if(str[i]=='('){ki.cha((i+1)/2,-1);}
		else{ki.cha((i+1)/2,1);clo.ins(i);}
	}
	dco[(1<<19)]=0;
	while(Q--){
		int q;cin>>q;q--;
		if(str[q]=='('){
			str[q]=')';
			clo.ins(q);
			ki.cha((q+1)/2,2);
			int ter=*clo.begin();
			cout<<ter+1<<endl;
			ki.cha((ter+1)/2,-2);
			clo.era(ter);
			str[ter]='(';
		}else{
			//cerr<<"de";
			str[q]='(';
			clo.era(q);
			ki.cha((q+1)/2,-2);
			int ter=ki.que((q+2)/2);
			if(ter==0){ter++;}
			cout<<ter+1<<endl;
			ki.cha((ter+1)/2,2);
			clo.ins(ter);
			str[ter]=')';
		}
		//cerr<<str<<endl;
	}
	return 0;
}
