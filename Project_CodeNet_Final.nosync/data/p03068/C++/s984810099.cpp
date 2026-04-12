#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define ll long long
#define mes(x,y) memset(x,y,sizeof(x))
using namespace std;
ll gar(ll a,ll b){//最大公约数 
return b==0?a:gar(b,a%b);
}
int main(){
	 int a,b;string c;
	 while(cin>>a>>c>>b){
	 	for(int i=0;i<c.length();i++){
	 		if(c[i]!=c[b-1]){
	 			c[i]='*';
			 }
		 }
		 cout<<c<<endl;
	 }
	return 0;
}
