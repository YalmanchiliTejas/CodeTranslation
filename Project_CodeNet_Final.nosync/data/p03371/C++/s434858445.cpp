#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y;
int main() {
	cin>>a>>b>>c>>x>>y;
	cout<< min({a*x+b*y,c*2*max(x,y),c*2*min(x,y)+(x>y?a*(x-y):b*(y-x))})<<endl;
}