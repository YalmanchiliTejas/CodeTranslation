#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
	
	int m,n;
	string s;
	int si;
	bool f;
	int player[1001];
	int np;
	int nc;

	while(1){

		cin>>m>>n;
		if(m==0&&n==0) break;

		for(int i=1;i<m;i++){
			player[i]=i+1;
		}
		player[m]=1;
		np=1;
		nc=m;

		for(int i=1;i<=n;i++){
			cin>>s;
			if(nc!=1){
				f=true;
				if(s=="Fizz"){
					if(i%3!=0){
						f=false;
					}
				}
				else if(s=="Buzz"){
					if(i%5!=0){
						f=false;
					}
				}
				else if(s=="FizzBuzz"){
					if(i%15!=0){
						f=false;
					}
				}
				else{
					si=0;
					for(int j=0;j<s.size();j++){
						if(s[s.size()-1-j]<'0'&&s[s.size()-1-j]>'9'||si>i){
							f=false;
							break;
						}
						si+=(s[s.size()-1-j]-'0')*pow(10,j);
					}
					if(i!=si||si%3==0||si%5==0) f=false;
				}
				if(!f){
					for(int j=1;j<=m;j++){
						if(player[j]==np){
							player[j]=player[np];
							player[np]=-1;
							np=player[j];
							break;
						}
					}
					nc--;
				}
				else np=player[np];
			}
		}

		for(int i=1;i<=m;i++){
			if(player[i]!=-1){
				cout<<i;
				nc--;
				if(nc!=0) cout<<" ";
				else cout<<endl;
			}
		}
	}

}