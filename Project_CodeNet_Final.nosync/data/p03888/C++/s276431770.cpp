#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	double a,b; cin >> a >> b;
	double ans=a*b/(a+b);
	printf("%.7f\n",ans );
}