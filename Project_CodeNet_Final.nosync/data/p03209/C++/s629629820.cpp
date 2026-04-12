#include<bits/stdc++.h>
using namespace std;
#define int long long



int lvlp(int n){
	if(n==0)return 1;
	else  return 2*lvlp(n-1)+1;
}
int lvln(int n){
	if(n==0)return 1;
	else  return 2*lvln(n-1)+3;
}

int f(int n,int x){
	if(n==0&&x==1)return 1;
	else if(x==1)return 0;
	else if(x<=lvln(n-1)+1)return f(n-1,x-1);
	else if(x==lvln(n-1)+2)return lvlp(n-1)+1;
	else if(x<=2*lvln(n-1)+2)return lvlp(n-1)+1+f(n-1,x-lvln(n-1)-2);
	else return 2*lvlp(n-1)+1;
}


signed main(){
	int n,x;cin>>n>>x;
	int ret=f(n,x);
	cout<<ret<<endl;



}