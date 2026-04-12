#include<bits/stdc++.h>
using namespace std;
int n;
char str[100100];
bool wlf[100100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	scanf("%s",str);
	for(int i=0;i<4;i++){
		wlf[0]=i&1;
		wlf[1]=(i>>1)&1;
		for(int j=2;j<n;j++){
			wlf[j]=wlf[j-1]^wlf[j-2]^(str[j-1]=='x');
		}
		bool flg=true;
		for(int i=0;i<n;i++){
			int le=(i-1+n)%n;
			int ri=(i+1+n)%n;
			if(wlf[ri]!=wlf[i]^wlf[le]^(str[i]=='x'))
			{
				flg=false;
				break;
			}
		}
		if(flg){
			for(int i=0;i<n;i++){
				if(wlf[i])
					cout<<'W';
				else
					cout<<'S';
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}