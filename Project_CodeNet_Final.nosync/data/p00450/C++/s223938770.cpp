#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main(){
	while(1){
		int n;
		int c[100010];
		
		scanf("%d",&n); if(n == 0)break;
		rep1(i,n){
			scanf("%d",&c[i]);
		}
		
		int a[100010],k[100010];
		int t = 0;
		
		rep1(i,n){
			if(i&1){
	  			if(t > 0 && a[t-1] == c[i]){
					k[t-1] ++;
				}
				else {
					a[t] = c[i];
					k[t] = 1;
					t ++;
				}
			}
			else {
				if(t > 1 && a[t-1] != c[i]){
					k[t-2] += k[t-1] + 1;
					t --;
				}
				else {
					a[t-1] = c[i];
					k[t-1] ++;
				}
			}
		}
		
		int ret = 0;
		rep(i,t){
			if(!a[i])ret += k[i];
		}
		
		printf("%d\n",ret);
	}
}