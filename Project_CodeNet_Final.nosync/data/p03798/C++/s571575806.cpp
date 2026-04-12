#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int N;
string s;
bool check(string aa){
	for(int i=1;i<N;i++){
		if(aa.at(i)=='S'){
			if(s.at(i)=='o')	aa+=aa.at(i-1);
			else if(s.at(i)=='x' && aa.at(i-1)=='S')	aa+='W';
			else if(s.at(i)=='x' && aa.at(i-1)=='W')	aa+='S';
		}
		else if(aa.at(i)=='W'){
			if(s.at(i)=='x')	aa+=aa.at(i-1);
			else if(s.at(i)=='o' && aa.at(i-1)=='S')	aa+='W';
			else if(s.at(i)=='o' && aa.at(i-1)=='W')	aa+='S';
		}
	}

	bool ans=false;
	if(aa.at(0)==aa.at(N)){
		if(s.at(0)=='o'){
			if(aa.at(0)=='S' && aa.at(N-1)==aa.at(1))	ans=true;
			else if(aa.at(0)=='W' && aa.at(N-1)!=aa.at(1))	ans=true;
		}
		else if(s.at(0)=='x'){
			if(aa.at(0)=='S' && aa.at(N-1)!=aa.at(1))	ans=true;
			else if(aa.at(0)=='W' && aa.at(N-1)==aa.at(1))	ans=true;
		}
	}

	if(ans){
		for(int i=0;i<N;i++)	cout << aa.at(i);
		cout << endl;
		return true;
	}
	return false;
}

int main(){
	cin >> N >> s;
		
	if(!check("SS")){
		if(!check("WW")){
			if(!check("SW")){
				if(!check("WS")){
					cout << -1 << endl;
				}
			}
		}
	}
	
	return 0;
}
