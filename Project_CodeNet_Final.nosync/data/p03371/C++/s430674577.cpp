#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,x,y;
    long long sum2;
    cin >> a >> b >> c >> x >> y;
    long long ans=a*x+b*y;
    long long sum1=2*c*max(x,y);
    if (x > y) sum2 = 2 * c * y + (x - y) * a;
	else sum2 = 2 * c * x + (y - x) * b;
	ans = min(min(ans, sum1), sum2);
	cout << ans;
}