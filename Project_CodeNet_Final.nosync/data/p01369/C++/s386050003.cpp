#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){
  string s;
  int isleft,c;
  while(cin>>s){
    if(s[0]=='#')break;
    else if(s[0]-'a'<7 ||( s[0]-'a'>15&&s[0]!='u'&&s[0]!='y'))isleft=1;
    else isleft=0;
    c=0;
    REP(i,s.size()){
      if(s[i]-'a'<7 ||( s[i]-'a'>15&&s[i]!='u'&&s[i]!='y')){
	if(!isleft){
	  c++;
	  isleft++;
	}
      }else{
	if(isleft){
	  c++;
	  isleft--;
	}
      }
    }  
    cout << c << endl;
  }
  
  return 0;
}