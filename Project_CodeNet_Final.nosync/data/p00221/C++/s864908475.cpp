#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

 
int main(){
	int P[100005]={};
	for(int i=0;i<10001;i++){
		P[i]=i;
		if(i%15==0)P[i]=70000;
		else if(i%5==0)P[i]=50000;
		else if(i%3==0)P[i]=30000;
	}

	
	int n,m;
	while(1){
		string s;
	bool F[1005]={};
	cin>>n>>m;if(n==0&&m==0)break;

	for(int i=1;i<=n;i++)
		F[i]=true;

	int K=1;
	bool FF=false;
	for(int I=1;I<=m;I++){

		cin>>s;int x=K;
		if(FF==false){
		int Q=0;
		for(int i=0;i<s.size();i++)
			{
				Q*=10;
				Q+=s[i]-'0';
		}
		
		if(I%15==0&&s!="FizzBuzz"){F[K]=false;}//cout<<"W";}
		else if(I%5==0&&s!="Buzz"){F[K]=false;}//cout<<"$";}
		else if(I%3==0&&s!="Fizz"){F[K]=false;}//cout<<"#";}
		
		else if(Q!=I&&s!="FizzBuzz"&&s!="Buzz"&&s!="Fizz"){F[K]=false;}//cout<<"P";}
		
		if(I%15==0&&s=="FizzBuzz"){F[K]=true;}//cout<<"W";}
		else if(I%5==0&&s=="Buzz"&&s!="FizzBuzz"){F[K]=true;}//cout<<"$";}
		else if(I%3==0&&s=="Fizz"&&s!="FizzBuzz"){F[K]=true;}//cout<<"#";}
	//	else F[K]=false;
		//if(F[K]==false)cout<<"%%"<<" "<<Q;

		for(int i=K+1;i<=n;i++){
			if(F[i]==true){x=i;break;}
		}
		if(x==K){
			for(int i=1;i<K;i++){
				if(F[i]==true){x=i;break;}
			}
		}
		}//if(x==K)FF=true;}
		K=x;
		int y=K;
		for(int i=K+1;i<=n;i++){
			if(F[i]==true){y=i;break;}
		}
		if(y==K){
			for(int i=1;i<K;i++){
				if(F[i]==true){y=i;break;}
			}
		}
		if(y==K)FF=true;





		//cout<<K<<endl;
	}
	bool H=false;

	
	for(int i=1;i<=n;i++)
	{
		if(F[i]==true){
			if(H==true)cout<<" ";
			cout<<i;
			H=true;
		}
	}
	cout<<endl;
	}
	return 0;
}
		