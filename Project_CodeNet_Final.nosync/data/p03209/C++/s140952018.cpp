#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#define INF 1000000000000000000
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>
using namespace std;
int dx[5]={1,0,-1,0,0},dy[5]={0,1,0,-1,0};
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}
int lcm(int a,int b){if(a==0){return b;} return a/gcd(a,b)*b;}

int start,x;
int ans=0;
int p[60];
int num(int level){
	if(level==1) return 5;
	int ans=2*num(level-1)+3;
	return ans;
}
int saiki(int level,int layer){
	if(level==1){
		if(layer>=5) return 3 ;
		else return layer-1;
	}
	int n=num(level);
	int m=(n-2+1)/2;
	int ret=0;
	if(layer==m+1) ret=saiki(level-1, m-2)+1;
	else if(layer<m+1){ 
		if(layer==1) ret=0;
		else ret=saiki(level-1, layer-1);
	}else{ 
		int w=layer-m-1;
		ret=saiki(level-1, w)+1;
		ret+=p[level-1];
	}
	return ret;
}

signed main(){
	cin>>start>>x;
	p[0]=1;
	for(int i=1; i<=55; i++){
		p[i]=p[i-1]*2+1;
	}
	cout<<saiki(start, x)<<en;
}

