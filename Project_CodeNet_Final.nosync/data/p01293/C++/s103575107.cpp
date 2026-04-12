#include <bits/stdc++.h>
using namespace std;

int main(){
	string table1 = "23456789TJQKA";
	char trump;
	while( cin >> trump && trump != '#' ){
		string table2 = "SHDC";
		remove(table2.begin(),table2.end(),trump);
		table2[table2.size()-1] = trump;
		vector< pair<pair<int,int>,int> > r[13];
		for(int j = 0 ; j < 4 ; j++){
			for(int i = 0 ; i < 13 ; i++){
				string str; cin >> str;
				r[i].push_back({{str[1],table1.find(str[0])},j});
			}
		}
		int win[2] = {};
		int nextLeader = 0;
		for(int i = 0 ; i < 13 ; i++){
			char led = r[i][nextLeader].first.first;
			for(int j = 0 ; j < 4 ; j++){
				r[i][j].first.first = ( trump == r[i][j].first.first ? 2 : led == r[i][j].first.first ? 1 : 0 );
			}
			sort(r[i].rbegin(),r[i].rend());
			nextLeader = r[i][0].second;
			win[r[i][0].second%2]++;
			
		}
		if( win[0] > 6 ){
			cout << "NS" << " " << win[0] - 6 << endl;
		}else{
			cout << "EW" << " " << win[1] - 6 << endl;
		}
	}
}