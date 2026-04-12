//Written by Zhu Zeqi
//Come on,baby
//Hack,please
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define CLR(x) memset(x,0,sizeof x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define MAX 1000000000000000000
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 0x3f3f3f3f
typedef long long ll;
//orz yht
using namespace std;
string i_s(int x){
	if(x==0)
	return "0";
	string ret="";
	while(x){
		ret=ret+(char)(x%10+'0');
		x/=10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
string add(string a,string b){
	if(a=="")
	a="0";
	if(b=="")
	b="0";
	if(a.length()<b.length())
	swap(a,b);
	while(b.length()<a.length()){
		b='0'+b;
	}
	for(int i=0;i<a.length();i++){
		a[i]=a[i]+(b[i]-'0');
	}
	bool big=false;
	for(int i=a.length()-1;i>=0;i--){
		if(big){
			a[i]++;
		}
		big=false;
		if(a[i]>'9'){
			a[i]=a[i]-10;
			big=true;
		}
	}
	if(big)
	a='1'+a;
	return a;
}
string mul(string a,string b){
	vector<int> va,vb;
	if(a=="0" || b=="0")
	return "0";
	string ans;
	for(int i=0;i<a.length();i++){
		va.push_back(a[i]-'0');
	}
	for(int i=0;i<b.length();i++){
		vb.push_back(b[i]-'0');
	}
	reverse(va.begin(),va.end());
	reverse(vb.begin(),vb.end());
	vector<int> res;
	res.clear();
	res.resize(1005);
	for(int i=0;i<a.length();i++){
		for(int j=0;j<b.length();j++){
			res[i+j]+=(va[i]*vb[j]);
		}
	}
	for(int i=0;i<1005;i++){
		if(res[i]>9){
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	for(int i=0;i<1005;i++){
		ans+=(res[i]+'0');
	}
	reverse(ans.begin(),ans.end());
	int k=0;
	while(ans[k]=='0'){
		k++;
	}
	ans=ans.substr(k);
	return ans;
}
bool is_prime(int n){
	if(n<2)
    return false;
    for(int i=2;i*i<=n;i++)
    if(n%i==0)
    return false;
    return true;
}
int n,fa[100005],cnt,ans;
struct node{
	int x,y,id;
}a[100005];
struct edge{
	int u,v,w;
}e[100005];
bool cmp1(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
bool cmpe(edge a,edge b){
	return a.w<b.w;
}
int fnd(int x){
	return fa[x]==x?x:fa[x]=fnd(fa[x]);
}
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		fa[i]=i;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=2;i<=n;i++){
		e[cnt].u=a[i].id;
		e[cnt].v=a[i-1].id;
		e[cnt++].w=a[i].x-a[i-1].x;
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=2;i<=n;i++){
		e[cnt].u=a[i].id;
		e[cnt].v=a[i-1].id;
		e[cnt++].w=a[i].y-a[i-1].y;
	}
	sort(e,e+cnt,cmpe);
	for(int i=0;i<cnt;i++){
		int u=e[i].u,v=e[i].v;
		int fx=fnd(u),fy=fnd(v);
		if(fx!=fy){
			ans+=e[i].w;
			fa[fx]=fy;
			n--;
			if(n==1)
			break;
		}
	}
	cout<<ans;
	//system("pause");
	return 0;
}