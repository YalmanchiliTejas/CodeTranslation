#include <bits/stdc++.h>
using namespace std;
int A,B,C;
int getX(int x){
	return (A*x+B)%C;
}
int main(){
	int n,x,y;
	while(cin>>n>>A>>B>>C>>x,n){
		int cnt=0;bool g=false,m=false;
		for(int i=0;i<n;i++){
			cin>>y;
			if(cnt==0 && x==y && !m){
				m=true;
				continue;
			}
			while(1){
				x=getX(x);
				cnt++;
				if(x==y)break;
				if(cnt>10000){
					g=true;
					break;
				}
			}
		}
		if(g||cnt>10000)cout<<-1<<endl;
		else cout<<cnt<<endl;
	}
}