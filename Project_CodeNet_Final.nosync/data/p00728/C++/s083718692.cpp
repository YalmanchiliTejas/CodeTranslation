#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <sstream>
#include <complex>
#include <climits>
using namespace std;

#define REP(i,a,n) for(int i=(a);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define EPS 1e-8

int main(){
	int n;
	int data[128];
	while(scanf("%d",&n),n){
		rep(i,n)scanf("%d",data+i);
		sort(data,data+n);
		int sum = 0;
		REP(i,1,n-1)sum+=data[i];
		printf("%d\n",sum/(n-2));
	}
	return 0;
}