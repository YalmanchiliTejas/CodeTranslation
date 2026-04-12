#include<iostream>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include <cstdlib>
#include<algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
const long long INF=10000000000000LL;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,M,K=1,C;
ll A,B,W;
ll T,a,b;
double v[55],D[55],Q,l,r;
ll ans=0;
//bool D[100005];
ll S[50][50]={};
string str1[55],str2="abcdefghijklmnopqrstuvwxyz";
map<string,int> m;

int main(){
	cin>>N;
	cout<<N*800-(N/15)*200<<endl;
	return 0;
}
