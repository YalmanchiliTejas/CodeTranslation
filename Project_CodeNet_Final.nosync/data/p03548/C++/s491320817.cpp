#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define pi acos(-1)
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef pair<int,int> p;
typedef long long ll;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	if(x<(y+2*z))cout<<0<<endl;
	else{
		x-=(y+2*z);
		cout<<1+x/(y+z)<<endl;
	}
	return 0;
}