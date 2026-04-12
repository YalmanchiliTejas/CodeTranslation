#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <cfloat>
#include <map>
using namespace std;

struct data{
	
	string name;
	int w;
	int l;
	int e;
	int t;
	static bool s  (const data& x,const data& y){
        return x.t>y.t;
    }
};

int main(){
	
	int n;
	int f=0;
	while(cin>>n,n!=0){
		if(f!=0)
		cout<<endl;
		vector<data> m(n);
		for(int i=0;i<n;i++){
			cin>>m[i].name>>m[i].w>>m[i].l>>m[i].e;
			m[i].t=m[i].w*3+m[i].e;
		}
		sort(m.begin(),m.end(),data::s);
		for(int i=0;i<n;i++)
			cout<<m[i].name<<","<<m[i].t<<endl;
		f=1;
	}
}