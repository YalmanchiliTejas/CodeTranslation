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

typedef pair<int,int> P;
int a,b;
P p[5];

int main(){
	while(cin>>a>>b){
		if(!a)return 0;
		p[0]=make_pair(a+b,0);
		for(int i=1;i<5;i++){
			cin>>a>>b;
			p[i]=make_pair(a+b,i);
		}
		sort(p,p+5);
		cout<<(char)('A'+p[4].second)<<" "<<p[4].first<<endl;
	}
}