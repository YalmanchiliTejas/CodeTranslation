
// Problem : C - Half and Half
// Contest : AtCoder - AtCoder Beginner Contest 095
// URL : https://atcoder.jp/contests/abc095/tasks/arc096_a?lang=en
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)n;i++)
#define REP(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
#define mod 1000000007
int lcm(int x,int y){
	return x/__gcd(x,y)*y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int cost1=a*x+b*y;
    int cost2=0;
    if(x<y){
    	cost2=min(c*2*x+(y-x)*b,y*c*2);
    }else{
    	cost2=min(c*2*y+(x-y)*a,x*c*2);
    }
    cout<<min(cost1,cost2)<<endl;
    return 0;
}
