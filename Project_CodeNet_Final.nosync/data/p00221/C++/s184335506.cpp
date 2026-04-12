#include <bits/stdc++.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;
int main(){
	int m,n;
	char s[9];
	while(scanf("%d%d",&m,&n)&&m&&n){
		bool mem[m];
		REP(i,m)mem[i]=false;
		int p=0,c=1;
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			if(c<m){
				int f=0;
				if(i%15==0){
					if(strcmp(s,"FizzBuzz"))f=1;
				}else if(i%5==0){
					if(strcmp(s,"Buzz"))f=1;
				}else if(i%3==0){
					if(strcmp(s,"Fizz"))f=1;
				}else{
					if(i!=atoi(s))f=1;
				}
				if(f)mem[p]=i,++c;
				do{
					p=(p+1)%m;
				}while(mem[p]);
			}
		}
		int f=0;
		for(int i=0;i<m;i++){
			if(!mem[i]){
				printf(f?" %d":"%d",i+1);
				f=1;
			}
		}
		printf("\n");
	}
	return 0;
}