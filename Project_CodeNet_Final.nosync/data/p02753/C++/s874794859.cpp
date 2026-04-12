#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#define ll long long 
#define d double
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	string s;
	cin>>s;
	map<char,int> count;
	for(char c:s){
      count[c]++;
	}
	 
	 
	if(count['A']<3&&count['A']>=1){
		cout<<"Yes"<<endl;	
	}
	
	else{	
		cout<<"No"<<endl;
	 } 
	
    return 0;
}