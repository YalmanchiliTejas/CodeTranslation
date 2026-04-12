#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REP(i,n) FOR(i,0,n)
typedef vector<int> vi;
typedef vector<vi> vii;

int main(){
	string s;
	string left="qwertasdfgzxcvb";
	while(cin>>s,s!="#"){
		int p=0;
		int ans=0;
		REP(i,s.length()){
			if(left.find(s[i])!=left.npos){
				ans+=p==2;
				p=1;
			}else{
				ans+=p==1;
				p=2;
			}
		}
		cout<<ans<<endl;
	}
}