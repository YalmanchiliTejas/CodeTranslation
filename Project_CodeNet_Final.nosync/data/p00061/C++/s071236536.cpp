#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define rp(a) while(a--)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	char d;
	int a,b;
	int t[102]={0};
	while(cin>>a>>d>>b,a||b)t[a]=b;
	int rank[102]={0};
	int no=0;
	int mat=1e4;
	while(mat){
		int ma=0;
		no++;
		rep(i,102)if(mat>t[i])ma=max(ma,t[i]);
		rep(i,102)if(ma==t[i])rank[i]=no;
		mat=ma;
	}
	while(cin>>a)cout<<rank[a]<<endl;
}