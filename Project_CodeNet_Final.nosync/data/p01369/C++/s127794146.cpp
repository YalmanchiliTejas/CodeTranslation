#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
#define ck(n,a,b) (a<=(n)&&(n)<b)
using namespace std;


int main(){
	string s;
	set<char> right{'y','u','i','o','p','h','j','k','l','n','m'};
	while(cin>>s && s!="#"){
		bool flag=true;//true:right
		int ans=0;
		if(right.find(s[0])==right.end()) flag=false;
		REP(i,1,(int)s.size()){
			if(right.find(s[i])==right.end()&&flag) {
				ans++;
				flag=false;
			}else if(right.find(s[i])!=right.end()&&!flag){
				ans++;
				flag=true;
			}
		}
		p(ans);
	}
	return 0;
}