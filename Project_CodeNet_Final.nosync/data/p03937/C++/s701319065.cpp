#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
 
using namespace std;
typedef long long ll;
 
 
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<int> G[100005];
std::vector<P> tree[100010];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
ll i,j,k;
ll n,m;
ll a[100005];
bool color[100005];
ll sum=0;
bool muri=false;
char s[5];
ll kazu=0;
ll h,w;
 
int main(){
	cin>>h>>w;
	for(i=0;i<h;i++){
		cin>>s;
		for(j=0;j<w;j++){
			if(s[j]=='#')kazu++;
		}
	}
	if(kazu==h+w-1){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}