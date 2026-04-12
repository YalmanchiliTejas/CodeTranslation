#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
	string S;
	int T[100],sum,e;
	while(true){
		cin>>S;
		if(S=="#"){
			break;
		}
		sum=0;
		memset(T,0,sizeof(T));
		for(int i=0;i<S.size();i++){
			e=S[i]-'a'+1;
			if((((e==17 || e==23) || (e==5 || e==18)) || ((e==20 || e==1) || (e==19 || e==4))) || (((e==6 || e==7) || (e==26 || e==24)) || ((e==3 || e==22) || e==2)))
			{
				T[i]=1;
			}
			if(i==0){

			}
			else if(T[i]!=T[i-1]){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}