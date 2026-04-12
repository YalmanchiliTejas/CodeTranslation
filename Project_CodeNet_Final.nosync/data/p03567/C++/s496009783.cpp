/*This is the solution from Ling2Feng1, no matter AC or not.*/
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<cstdio>
#include<string>
#include<vector>
#include<math.h>
#include<time.h>
#include<utility>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
int main(){
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A'&&s[i+1]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		} 
	}
	cout<<"No"<<endl;
	return 0;
}