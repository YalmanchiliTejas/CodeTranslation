#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

string itos(int n){
	stringstream ss;
	ss<<n;
	return ss.str();
}

bool fizzbuzz(int i,string s){
	if(i%15==0){
		if(s=="FizzBuzz")return true;
	}else if(i%3==0){
		if(s=="Fizz")return true;
	}else if(i%5==0){
		if(s=="Buzz")return true;
	}else{
		if(s==itos(i))return true;
	}
	return false;
}

int main(){
	int m,n;
	while(cin>>m>>n,m||n){
		bool person[m+1];
		rep(i,m+1)person[i]=true;
		person[0]=false;
		string s;
		int now=1;
		loop(i,1,n+1){
			cin>>s;
			int check=0;
			if(!person[now])for(int j=0;j<m && !person[now];j++){now++;if(now>m)now-=m;}
			loop(j,1,m+1)if(person[j])check++;
			if(check==1)continue;
			if(!fizzbuzz(i,s)){
				person[now]=false;
			}
			now++;
			if(now>m)now-=m;
		}
		vector<int> vec;
		loop(i,1,m+1)if(person[i])vec.push_back(i);
		if(vec.size()==1)cout<<vec[0]<<endl;
		else{
			cout<<vec[0];
			loop(i,1,vec.size())cout<<" "<<vec[i];
			cout<<endl;
		}
	}
	return 0;
}