#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
string toString(int n){
	stringstream s;
	s << n;
	return s.str();
}
bool check(int times,string num){
	bool ans;
	if(times%15==0)
	ans=num=="FizzBuzz";
	else if(times%5==0)
	ans=num=="Buzz";
	else if(times%3==0)
	ans=num=="Fizz";
	else
	ans=(num==toString(times));
	return ans;
}
int main() {
	// your code goes here
	int N;
	
	while(cin >> N && N!=0){
		int T=0,player=0;
		string num;
		int dead[1001]={};
		bool ans=false;
		int deader=0;
		cin >> T;
		for(int times=1;times<=T;times++){
			cin >> num;
			if(deader+1!=N){
			ans=check(times,num);
			while(dead[(++player-1)%N+1]);
			if(!ans){
			dead[(player-1)%N+1]=true;
			deader++;
			}
			}
		}
		bool d=false;
		for(int i=1;i<=N;i++)
			if(dead[i]==false){
				if(d)
				cout << " ";
				cout << i;
				d=true;
			}
		cout << endl;
	}
	return 0;
}