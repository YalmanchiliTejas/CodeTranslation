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

int n,m,t[20000];

int main(){
	while(cin>>n>>m){
		if(!(n+m))return 0;
		for(int i=0;i<n+m;i++)cin>>t[i];
		sort(t,t+n+m);
		int dif=0;
		for(int i=0;i<n+m;i++){
			if(!i)dif=t[i];
			else dif=max(dif,t[i]-t[i-1]);
		}
		cout<<dif<<endl;
	}
}