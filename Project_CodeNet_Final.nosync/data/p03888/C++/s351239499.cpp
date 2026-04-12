#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b;
	cin>>a>>b;
	double x=1;
	double c=x/a;
	double d=x/b;
	printf("%.9lf\n",x/(c+d));
	return 0;
}
