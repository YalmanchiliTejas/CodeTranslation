#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

#define M 1111111
int sosu[M];

int main(){
	
	while(1){
		int a;
		cin>>a;
		if(a==0)break;
		
		int b[1111]={0};
		
		rep(i,a){
			int c;
			cin>>c;
			b[c]++;
		}
		
		int ans = 0;
		int st = -1;
		int en = 0;
		rep(i,1111){
			if(b[i]!=0){
				if(st==-1)st=i;
				en = i;
				ans += i*b[i];
			}
		}
		
		ans -= st+en;
		printf("%d\n",ans/(a-2));
	}
}