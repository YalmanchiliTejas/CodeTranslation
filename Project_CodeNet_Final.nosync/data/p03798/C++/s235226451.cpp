#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define ll __int64
//#define __int64 long long
#define P pair<int,int>
string s;
int n;
string t[4];


string che(string a){
	string x;
	x.resize(n);
	x[0]=a[0];
	x[1]=a[1];
	for(int i=1;i<n-1;i++){
		if(s[i]=='o'){
			if((x[i-1]=='S'&&x[i]=='S')||(x[i-1]=='W'&&x[i]=='W'))x[i+1]='S';
			else x[i+1]='W';
		}
		else{//x
			if((x[i-1]=='S'&&x[i]=='W')||(x[i-1]=='W'&&x[i]=='S'))x[i+1]='S';
			else x[i+1]='W';
		}
	}
	//cout<<x<<endl;
	bool ok=1;
	int l,r;
	rep(i,n){
		l=i-1;
		r=i+1;
		if(r>=n)r=0;
		if(l<0)l=n-1;
		if(s[i]=='o'){
			if((x[i]=='S'&&x[l]!=x[r])||(x[i]=='W'&&x[l]==x[r]))ok=0;
		
		}
		else{
				if((x[i]=='S'&&x[l]==x[r])||(x[i]=='W'&&x[l]!=x[r]))ok=0;
		}
	}
	if(ok)return x;
	return "#";
}
int main(){
	cin>>n>>s;

	t[0]="SS";
	t[1]="SW";
	t[2]="WS";
	t[3]="WW";

	rep(i,4){
		string a=che(t[i]);
		if(a!="#"){cout<<a<<endl;return 0;}
	}
	cout<<-1<<endl;
	return 0;
}
