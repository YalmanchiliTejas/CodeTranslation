#include <iostream>
#include <string>

#define lli long long int
#define REP(i,n) for(int i=0;i<n;i++)
#define DEBUG 0

#define S 1
#define W -1

using namespace std;

void show(int *data,int n){
	REP(i,n){
		cout<<data[i];
	}
	cout<<endl;
}

string ans(int *data,int n){
	string str="";
	REP(i,n){
		if(data[i]==S){
			str+="S";
		}else{
			str+="W";
		}
	}
	return str;
}


int func(char c,int *data,int n){
	int num;
	if(c =='o'){
		num=1;
	}else{
		num=-1;
	}
	if(DEBUG)show(data,n);
	return num*data[n-1]*data[n];
}

int calc(int *data,int n,string str){
	for(int i=1;i<n-2;i++){
		data[i+1]= func(str.at(i),data,i);
	}
	if(data[n-1] == func(str.at(n-2),data,n-2) && data[0] == func(str.at(n-1),data,n-1)){
		cout<<ans(data,n)<<endl;
		return 1;
	}
	return -1;
}

lli min(lli a,lli b){
	return a <= b ? a : b;
}

void init(int *data,int n,int i,char c){
	int num;
	if(c =='o'){
		num=1;
	}else{
		num=-1;
	}
	int first[4] = {S,S,W,W};
	int second[4]= {S,W,S,W};
	REP(j,n){
		data[j]=0;
	}
	data[0]=first[i];
	data[1]=second[i];
	data[n-1]=num*data[0]*data[1];
}

int main(){
	int n;
	int *data;
	string str;
	cin>>n>>str;
	data = new int[n];
	REP(i,4){
		init(data,n,i,str.at(0));
		if(calc(data,n,str)==1){
			return 0;
		}
	}

	cout<<"-1"<<endl;
	return 0;

}