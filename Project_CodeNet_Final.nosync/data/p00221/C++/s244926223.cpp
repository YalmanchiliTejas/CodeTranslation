#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
bool b[2003];

#define REP(a) for(int i=0;i<a;i++)

int main()
{
	bool f=0;
	int x,m,n,j;
	int prev[2002],next[2002],p,v=1;
	string c,d;
	cin>>m>>n;
	while(m!=0||n!=0){
		x=m;
		REP(m){
			next[i]=(i+1)%m;
			prev[i]=(i+m-1)%m;
		}
		p=0;
		REP(n){
			cin>>c;
			if(f==0){
				if(c!="Fizz"&&(i+1)%3==0&&(i+1)%5!=0){
					v=0;
					m--;
				}
				else if(c!="Buzz"&&(i+1)%3!=0&&(i+1)%5==0){
					v=0;
					m--;
				}
				else if(c!="FizzBuzz"&&(i+1)%3==0&&(i+1)%5==0){
					v=0;
					m--;
				}
				else if(atoi(c.c_str())!=i+1&&(i+1)%3!=0&&(i+1)%5!=0){ 
					v=0;
					m--;
					//	cout<<'A';
				}

			}
			if(v==0) {
				prev[next[p]]=prev[p];
				next[prev[p]]=next[p];
				prev[p]=-1;
				v=1;
				
			}
			p=next[p];
			if(m==1) f=1;
		}
		REP(x){
		if(prev[i]!=-1){
		cout<<i+1;
		p=i;
		break;
		}
		}
		for(v=p+1;v<x;v++){
		if(prev[v]!=-1) cout<<" "<<v+1;
		}
		cout<<endl;
		cin>>m>>n;
		f=0;
		j=1;
	}
	return 0;
}