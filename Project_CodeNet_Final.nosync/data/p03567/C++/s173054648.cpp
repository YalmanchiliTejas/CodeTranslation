#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
 
 
int main(){
	int n;
	string s;
	int i,j;
	int temp;
	int dx[4] = {-1,0,0,1};
	int dy[4] = {0,-1,1,0};
	char ac[2] = {'A','C'};
	
 
	cin >> s;
	
	
	REP(i,s.size()){
		if(s[i]==ac[0]){
			if(s[i+1]==ac[1]){
				printf("Yes\n");
				return 0;
			}	
		}
	}
	
	printf("No\n");
	return 0;
}