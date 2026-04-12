#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define mod 1000000007
#define p pair<int,int>
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
using namespace std;
int POW(int x,int y){return int(pow(double(x),double(y)));}



int main(){
	
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	rep(i,n){
		cin>>x[i];
		y[i]=x[i];
	}
	sort(x.begin(),x.end());

	int a=x[n/2];
	int b=x[n/2-1];
	rep(i,n){
		if(y[i]<a){
			cout<<a<<endl;
		}else{
			cout<<b<<endl;
		}
	}


}
