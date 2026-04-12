#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
bool l[26]={1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1};
int main(){
	while(true){
		string s;
		cin >> s;
		if(s[0]=='#') break;
		bool now=l[s[0]-'a'];
		int cnt=0;
		rep(i,s.size()){
			if(l[s[i]-'a']!=now) cnt++;
			now=l[s[i]-'a'];
		}
		cout << cnt << endl;
	}
	return 0;
}