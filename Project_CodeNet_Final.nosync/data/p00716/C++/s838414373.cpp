#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

int main(){
	int T;
	cin>>T;
	
	rep(t,T){
		int a,b,n;
		cin>>a>>b>>n;
		
		int maxi = 0;
		
		rep(i,n){
			int c;
			cin>>c;
			
			double d;
			int e;
			cin>>d>>e;
			
			int val = 0;
			if(c==1){
				val = a;
				rep(j,b){
					val = val+(int)(val*d)-e;
				}
			}else{
				val = a;
				int r = 0;
				rep(j,b){
					r += (int)(val*d);
					val -= e;
				}
				val += r;
			}
			maxi = max(maxi,val);
		}
		
		printf("%d\n",maxi);
	}
}