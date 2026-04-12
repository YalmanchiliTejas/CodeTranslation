#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int h, w;
	cin>>h>>w;
	string m;
	vector<string> v;
	int b=0,c;
	rep(i, h){
		c=0;
		cin>>m;
		rep(j, w){
			if(m[j]=='.')
				c++;
		}
		if(c!=w){
			v.push_back(m);
			b++;
		}
	}
	int d;
	vector<int> a;
	rep(i, w){
		d=0;
		rep(j, b){
			if(v[j][i]=='.')
				d++;
		}
		if(d==b)
			a.push_back(i);
	}
	a.push_back(1000);
	int e;
	rep(i, b){
		e=0;
		rep(j, w){
			if(j!=a[e])
				cout<<v[i][j];
			else
				e++;
		}
		cout<<endl;
	}
	return 0;
}