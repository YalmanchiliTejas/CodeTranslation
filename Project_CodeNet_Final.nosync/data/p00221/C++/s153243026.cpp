#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main(){
	for(int m,n;cin>>m>>n,m;){
		static bool flg[1000];
		static int bef[1000],nxt[1000];
		for(int i=0;i<m;i++)	flg[i]=true,bef[i]=(i+m-1)%m,nxt[i]=(i+1)%m;

		int pos=0,num=m;
		for(int i=1;i<=n;i++){
			string s;	cin>>s;
			if(num==1)	continue;

			bool ok=true;
			if(i%15==0){	if(s!="FizzBuzz")	ok=false;	}
			else if(i%3==0){	if(s!="Fizz")	ok=false;	}
			else if(i%5==0){	if(s!="Buzz")	ok=false;	}
			else{
				stringstream ss;	ss<<i;
				if(s!=ss.str())	ok=false;
			}

			if(!ok){
				flg[pos]=false;
				int tmpb=bef[pos],tmpn=nxt[pos];
				bef[tmpn]=tmpb;
				nxt[tmpb]=tmpn;
				num--;
			}
			pos=nxt[pos];
		}

		for(int i=0,j=0;i<m;i++)	if(flg[i])	cout<<(j++?" ":"")<<i+1;
		cout<<endl;
	}

	return 0;
}