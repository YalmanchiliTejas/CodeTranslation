#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
bool Fbcheck(string str, int i){
	bool flg = false;
	stringstream ss;
	string strans;
	ss << i;
	strans = ss.str();
	if(i%3 == 0 && i%5 == 0){
		if(str == "FizzBuzz") flg = true;
	}else if(i%3==0){
		if(str == "Fizz") flg = true;
	}else if(i%5==0){
		if(str == "Buzz") flg = true;
	}else{
		if(str == strans) flg = true;
	}
	return flg;
}
int main(){
	int i, n, m;
	string str;
	while(true){
		cin>>m>>n; if(m==0 && n==0) break;
		vector<int> players;
		for(i=0;i<m;i++){
			players.push_back(i+1);
		}
		for(i=1;i<=n;i++){
			cin>>str;
			if(players.size() > 1){
				if(Fbcheck(str, i)){
					//cout<<"o\n";
					players.push_back(players.front());
					players.erase(players.begin());
				}else{
					//cout<<"x\n";
					players.erase(players.begin());
					
				}
			}
		}
		//cout<<"players.size()="<<players.size()<<endl;
		//cout<<"result\n";
		sort(players.begin(), players.end());
		cout<<players.front();
		players.erase(players.begin());
		while(players.empty() != true){
			cout<<" "<<players.front();
			players.erase(players.begin());
		}
		cout<<endl;
	}
	return 0;
}