#include <bits/stdc++.h>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){

    int X,Y,Z,ans=0;
    cin>>X>>Y>>Z;

    X-=2*Z;

    while(X>=Y){
        ans++;
        X-=Y;
        X-=Z;
    }

    cout<<ans<<endl;
    return 0;
}