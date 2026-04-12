#include<bits/stdc++.h>
#include<string>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007;
#define INF (1<<28)
#define int long long
#define double long double
#define floot10 cout<<fixed<<setprecision(10)
#define G 1

signed main(){
  string s;
  cin>>s;
  int n;
  cin>>n;
  int now=s[0]-'0';
  for(int i=1;i<s.size();i+=2){
    if(s[i]=='+'){
      now+=s[i+1]-'0';
    }
    if(s[i]=='*'){
      now*=s[i+1]-'0';
    }
  }
  int now2=0;
  int mode=-1;
  for(int i=0;i<s.size();i+=2){
    if(i==s.size()-1){
      if(mode==-1) now2+=s[i]-'0';
      else{
	now2+=mode*(s[i]-'0');
      }
    }
    else if(s[i+1]=='+'){
      if(mode==-1){
	now2+=s[i]-'0';
      }
      else{
	now2+=mode*(s[i]-'0');
	mode=-1;
      }
    }
    else{
      if(mode==-1) mode=s[i]-'0';
      else{
	mode*=s[i]-'0';
      }
    }
  }
  //cout<<now<<" "<<now2<<endl;
  if(n==now&&n==now2) cout<<"U"<<endl;
  else if(n==now) cout<<"L"<<endl;
  else if(n==now2) cout<<"M"<<endl;
  else cout<<"I"<<endl;
  return 0;
}

