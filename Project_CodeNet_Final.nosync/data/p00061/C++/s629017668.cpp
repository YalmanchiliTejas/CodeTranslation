#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<25;
const double pi=acos(-1);
const double eps=1e-8;
const vi emp;

int p,s,q;
char t;
vi S,ans(50);
map<int,int> M;

int main(){
	while(1){
		cin>>p>>t>>s;
		if(!p&&!s) break;
		S.push_back(-s);
		M[p]=s;
	}
	sort(S.begin(),S.end());
	S.erase(unique(S.begin(),S.end()),S.end());
	for(int i=0;i<S.size();i++) ans[-S[i]]=i+1;
	while(cin>>q) cout<<ans[M[q]]<<endl;
}