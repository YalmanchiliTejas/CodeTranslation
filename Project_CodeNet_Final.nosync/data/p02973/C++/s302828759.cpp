//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[100000+10];
int _next[100000+10],before[100000+10];
int flag[100000+10];
int res=0;
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	multiset<int> last;
	multiset<int> :: IT ite;
	rb(i,1,n){
		if(!last.empty()){
		ite=last.lower_bound(a[i]);
		if(ite!=last.begin()){
			ite--;
			last.erase(ite);
			last.insert(a[i]);
		}
		else{
			res++;
			last.insert(a[i]);
		}	
		}
		else{
			res++;
			last.insert(a[i]);
		}
	}
	cout<<res<<endl; 
	return 0;
}