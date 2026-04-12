#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,j,k) for(int i=j;i<(k);i++)

int main(){
	set<char> set_R;
	set_R.insert('y');
	set_R.insert('u');
	set_R.insert('i');
	set_R.insert('o');
	set_R.insert('p');
	set_R.insert('h');
	set_R.insert('j');
	set_R.insert('k');
	set_R.insert('l');
	set_R.insert('n');
	set_R.insert('m');
	string str;
	while(cin >> str){
		int flag=0,sum = 0;
		if(str == "#"){ return 0;}
		if(set_R.count(str[0])==1) { flag = 1 ;}
		rep(i,str.length()){
			if(flag==0&&set_R.find(str[i])!=set_R.end()){
				sum++;
				flag = 1;
			}else if(flag==1&&set_R.find(str[i])==set_R.end()){
				sum++;
				flag = 0;
			}
			
		}
		cout << sum << endl;
	}
	
	return 0;
	
}