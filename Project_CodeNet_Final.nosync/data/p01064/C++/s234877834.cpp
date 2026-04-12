#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int main(){
	int n;
	int a,d;
	int m;
	cin>>n>>a>>d>>m;
	vvi in(m,vi(3));
	rep(i,m)rep(j,3)cin>>in[i][j];
	int k;
	cin>>k;
	for(int i = m-1 ; i >= 0 ; i --){
		if(!in[i][0]){ // swap;
			if(in[i][1] <= k && k <= in[i][2]){
					k = in[i][2] + in[i][1] - k;
			}
		}
	}
	int v = a + d * (k-1);
	
	rep(i,m){
		if(in[i][1] <= k && k <= in[i][2]){
			if(in[i][0]==0){
				k = in[i][1] + in[i][2] - k;
			}else if(in[i][0]==1){
				v ++;
			}else if(in[i][0]==2){
				v /= 2;
			}
		}
	}
	cout<<v<<endl;
	
	
}