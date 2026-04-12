#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

string left_or_right(char word)
{
	string left="qwertasdfgzxcvb";
	string right="yuiophjklnm";
	
	if(right.find(word) != string::npos){
		return "R";
	}
	else{
		return "L";
	};

}

int main() {
	
	string word;
	string hand="";

	while(cin >> word)
	{
		if(word == "#"){ break; }
		
		int count=0;
			string tmp = left_or_right(word[0]);
		REP(i,1,word.length()){
			hand =  left_or_right(word[i]);
			if(hand != tmp){count++;}
			tmp = hand;
		}
		cout << count << endl;
	}
	return 0;
}