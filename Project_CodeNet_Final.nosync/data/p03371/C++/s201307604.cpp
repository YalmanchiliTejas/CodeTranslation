#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int A,B,C,X,Y;cin>>A>>B>>C>>X>>Y;
	int a,b;
	if(X > Y){
        if(A < 2*C) a = A * (X-Y);
        else a = 2*C * (X-Y);
    }else{
        if(B < 2*C) a = B * (Y-X);
        else a = 2*C * (Y-X);
    }
	if(A + B > 2 * C) b = min(X , Y) * 2 * C; 
	else b = min(X , Y) * (A + B);
	cout<<a + b<<endl;
}