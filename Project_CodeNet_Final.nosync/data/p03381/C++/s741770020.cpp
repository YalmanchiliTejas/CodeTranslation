#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define P pair<int,int>
#define ll __int64
//#define __int64 long long
//const ll M=1000000007;
int n;
P t[300000];
int z[300000];
int main(){
	cin>>n;
	rep(i,n){
		int x;
		cin>>x;
		t[i]=mp(x,i);
		z[i]=x;
	}

	//sort(t,t+n);
	sort(z,z+n);
	int mid=n/2;
	
	rep(i,n){
		if(t[i].first>=z[mid]){
			cout<<z[mid-1]<<endl;
		}
		
		else {cout<<z[mid]<<endl;}
	}
	return 0;
}
