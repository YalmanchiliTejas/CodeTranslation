#include<bits/stdc++.h>
using namespace std;



/*int sea(string s){
	reverse(s.begin(),s.end());
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum+=(s[i]-'0')*(int)pow(10,i);
	}
	return sum;
	}*/


string correct(int i){
	if(i%3==0 && i%5==0)return "FizzBuzz";
	else if(i%3==0)return "Fizz";
	else if(i%5==0)return "Buzz";
	else return to_string(i);
}

int main(){
	while(1){
	
		int m,n;
		int a[10000]={};
		set<int> done;
		cin>>m>>n;
		if(m==0 && n==0){break;}
		for(int i=0;i<m;i++){
			a[i]=i+1;
		}
		a[m]=1;
		int b=m;
		int w=1;
		int count=0;
		for(int i=1;i<=n;i++){
			string s;
			bool j=true;
			cin>>s;
			if(count<m-1){
				/*if(i%15==0 && s!="FizzBuzz"){j=false;}
				else if(i%5==0 && s!="Buzz"){j=false;}
				else if(i%3==0 && s!="Fizz"){j=false;}
				if(i%15!=0 && i%5!=0 && i%3!=0 && ){j=false;}				
				if(j){b=w; w=a[w];}
				if(!j){
				}*/
				if ( correct(i) != s ) {
					done.insert(i);
					a[b]=a[w]; done.insert(w); w=a[w]; count++;				
				} else {
					b=w; w=a[w];
				}
			}
		}
		bool d=true;
		for(int i=1;i<=m;i++){
			if(done.find(i)==done.end()){
				if(d){cout<<i; d=false;}
				else{cout<<" "<<i;}
			}
		}
		cout<<endl;




	}
	return 0;
}

