#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int m,n;
string s;
bool b[1001];

int main(){
	while(cin>>m>>n){
		if(!m)return 0;
		int c=1,p=m;
		fill(b,b+m+1,0);
		for(int i=1;i<=n;i++){
			//cout<<"player "<<c<<":"<<endl;
			cin>>s;
			if(!(i%15)){
				if(s!="FizzBuzz"){b[c]=1;p--;}
				//else cout<<"s"<<endl;
			}
			else if(!(i%3)){
				if(s!="Fizz"){b[c]=1;p--;}
				//else cout<<"s"<<endl;
			}
			else if(!(i%5)){
				if(s!="Buzz"){b[c]=1;p--;}
				//else cout<<"s"<<endl;
			}
			else{
				int f=0;
				if(s.size()<6){
					int cur=0,N=0;
					while(cur<s.size()){
						if(!isdigit(s[cur])){f=2;break;}
						N=N*10+s[cur++]-'0';
					}
					if(!f&&N==i)f=1;
				}
				if(f!=1){b[c]=1;p--;}
				//else cout<<"s"<<endl;
			}
			if(p==1){for(int j=i+1;j<=n;j++)cin>>s;break;}
			c++;
			if(c==m+1)c=1;
			while(b[c]){c++;if(c==m+1)c=1;}
		}
		int f=0;
		for(int i=1;i<=m;i++){
			if(!b[i]){
				if(f)cout<<" ";
				cout<<i;
				f=1;
			}
		}
		cout<<endl;
	}
}