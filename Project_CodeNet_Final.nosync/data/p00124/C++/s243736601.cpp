#include <iostream>
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

int N,a,b,c;
string s;

int main(){
	bool f=0;
	while(cin>>N){
		if(!N)return 0;
		if(f)cout<<endl;
		pair<int,pair<int,string> > p[10];
		for(int i=0;i<N;i++){
			cin>>s>>a>>b>>c;
			p[i]=make_pair(a*-3-c,make_pair(i,s));
		}
		sort(p,p+N);
		for(int i=0;i<N;i++)cout<<p[i].second.second<<","<<-1*p[i].first<<endl;
		f=1;
	}
}