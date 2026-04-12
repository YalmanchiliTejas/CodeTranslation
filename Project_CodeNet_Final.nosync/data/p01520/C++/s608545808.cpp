#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <complex>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<long long,int> P;
static const int INF=1<<24;

int main(){
	int n,t,e;
	int x[1100];
	cin>>n>>t>>e;
	rep(i,n){
		cin>>x[i];
		int tmp=x[i];
		rep(j,INF){
			if(x[i]>=t-e&&x[i]<=t+e){
				cout<<i+1<<endl;
				return 0;
			}
			if(x[i]>t+e) break;
			x[i]+=tmp;
		}
	}
	cout<<-1<<endl;
	return 0;
}