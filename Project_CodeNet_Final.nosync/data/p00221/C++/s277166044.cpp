#include <bits/stdc++.h>
using namespace std;
int power(int num)
{
    int p=1;
    for(;1<num;num--)p*=10;
    return p;
}
int main() {
    int n,m,a[3]={15,3,5};
    string str,fb[3]={"FizzBuzz","Fizz","Buzz"};
    while(cin>>m>>n,n,m){
        bool player[1000]={};
        for(int i=1,now=0,out=m;i<=n;i++,now=(now+1)%m){
			cin>>str;
			if(out>1){
				int num=0,co=-1;
				while(player[now])now=(now+1)%m;
				for(int j=0;j<3&&co<0;j++)if(i%a[j]<1)co=j;
				for(int j=0;j<str.size()&&co<0;j++)num+=(str[j]-'0')*power(str.size()-j);
				if(co>-1&&str!=fb[co]||co<0&&i!=num)player[now]=1;
				if(player[now])out--;
			}
		}
		for(int i=0,co=0;i<m;i++){
			if(!player[i]&&co>0)cout<<" ";
			if(!player[i]){
				cout<<i+1;
				co++;
			}
		}
		cout<<endl;
	}
}