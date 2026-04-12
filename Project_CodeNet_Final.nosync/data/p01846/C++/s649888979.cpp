#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <string>

#define REP(i,n)for (int i=0;i<(n);i++)
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ll long long
using namespace std;
typedef pair<int,int> P;

string fld[10];

void to_fld(string s){
	int p=0;
	REP(i,s.size()){
		if(s[i]=='/'){
			p++;
		}else if(s[i]=='b'){
			fld[p]+='b';
		}else{
			int c=s[i]-'0';
			REP(j,c)fld[p]+='.';
		}
	}
}

string to_string(){
	int i=0;
	string s="";
	while(fld[i]!=""){
		int c=0;
		REP(j,fld[i].size()){
			if(fld[i][j]=='b'){
				if(c>0){
					s+=c+'0';
					c=0;
				}
				s+='b';
			}else{
				c++;
			}
		}
		if(c>0){
			s+=c+'0';
		}
		s+='/';
		i++;
	}
	return s;
}

int main(){
	string s;
	while(1){
		cin>>s;
		if(s=="#")break;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		REP(i,10)fld[i]="";
		to_fld(s);
		fld[--a][--b]='.';
		fld[--c][--d]='b';
		s=to_string();
		s.erase(s.size()-1);
		cout<<s<<endl;
	}
}
