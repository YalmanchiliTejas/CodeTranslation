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

int s1,s2;

int main(){
	while(1){
		cin>>s1>>s2;
		if(!s1&&!s2) break;
		P ans;
		ans=P(0,s1+s2);
		for(int i=0;i<4;i++){
			cin>>s1>>s2;
			if(ans.second<s1+s2) ans=P(i+1,s1+s2);
		}
		int T=ans.first;
		if(!T) cout<<'A'<<' ';
		else if(T==1) cout<<'B'<<' ';
		else if(T==2) cout<<'C'<<' ';
		else if(T==3) cout<<'D'<<' ';
		else cout<<'E'<<' ';
		cout<<ans.second<<endl;
	}
}