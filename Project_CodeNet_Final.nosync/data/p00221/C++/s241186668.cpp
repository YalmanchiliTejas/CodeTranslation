#include <bits/stdc++.h>
using namespace std;
int power(int num)
{
	int ans=1;
	for(int i=0;i<num;i++)ans*=10;
	return ans;
}
int main() {
	int n,m;
	while(cin>>m>>n,n,m){
		string str;
		bool player[1000]={};
		for(int i=1,now=0,out=m;i<=n;i++,now=(now+1)%m){
			cin>>str;
			if(out>1){
				while(player[now])now=(now+1)%m;
				if(i%15==0&&str!="FizzBuzz"||i%3==0&&i%5>0&&str!="Fizz"||i%5==0&&i%3>0&&str!="Buzz")player[now]=1;
				else if(i%3>0&&i%5>0){
					int num=0;
					for(int j=0;j<str.size();j++)num+=(str[j]-'0')*power(str.size()-1-j);
					if(num!=i)player[now]=1;
				}
				if(player[now])out--;
			}
		}
		for(int i=0,co=0;i<m;i++){
			if(co==0&&!player[i]){
				cout<<i+1;
				co++;
			}
			else if(!player[i])cout<<" "<<i+1;
		}
		cout<<endl;
	}
}