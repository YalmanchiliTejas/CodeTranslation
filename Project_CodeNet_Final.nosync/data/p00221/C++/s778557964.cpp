#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


string to_s(int n){
	string s;
	while(n){
		s+=n%10+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
string FizzBuzz(int n){
	if(n%3==0&&n%5==0)return "FizzBuzz";
	if(n%3==0)return "Fizz";
	if(n%5==0)return "Buzz";
	return to_s(n);
}

int main(){
	int m,n;
	bool f[1000];
	while(cin>>m>>n,m|n){
		fill_n(f,m,true);
		string s;
		int rest=m;
		int num=1,a=0;
		for(int i=0;i<n;i++){
			cin>>s;
			if(rest==1)continue;		
			while(!f[a]){
				a=(a+1)%m;
			}
			if(s!=FizzBuzz(num)){
				f[a]=false;
				rest--;
			}
			a=(a+1)%m;
			num++;
		}
		bool first=true;
		for(int i=0;i<m;i++){
			if(!f[i])continue;
			if(!first)cout<<' ';
			first=false;
			cout<<i+1;
		}
		cout<<endl;
	}
	return 0;
}