#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Max 100009
ll n,m,a,b,ans;
ll v[Max],p[Max];

int main() {
	cin>>n;
	string sh;
	cin>>sh;
	cin>>m;
	for(int i=0;i<sh.size();i++){
		if(sh[i]==sh[m-1]) cout<<sh[i];
		else cout<<"*";
	}
	cout<<endl;
    return 0;
    
}