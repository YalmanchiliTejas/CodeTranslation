#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int N;
pair<int,pair<int,int> > p[10];

int main(){
	while(cin>>N&&N){
		rep(i,N)cin>>p[i].first>>p[i].second.first>>p[i].second.second;
		sort(p,p+N);
		rep(i,N)printf("%04d %02d %02d\n",p[i].first,p[i].second.first,p[i].second.second);
	}
}