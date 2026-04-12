#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
 
#define rep(n) for(int i=0; i<(n); i++)
#define pb(n) push_back((n))
 
//typedef long long ll;
 
using namespace std;

int main(){
	vector<pair<int,int> > v(101,pair<int,int>(0,1000));
	int i=0;
	while(1){
		int a,b;
		scanf("%d,%d",&a,&b);
		if(a==0&&b==0)break;
		v[i].first=b;
		v[i].second=a;
		i++;
	}
	sort(&v[0],&v[101]);
	reverse(&v[0],&v[101]);
	vector<int> r(101,0);
	int p=v[0].first;
	int rank=1;
	for(i=0; i<101; i++){
		if(p==v[i].first)r[v[i].second]=rank;
		else{
			rank++;
			p=v[i].first;
			r[v[i].second]=rank;
		}
	}
	while(scanf("%d",&i)!=EOF){
		cout<<r[i]<<endl;
	}
}