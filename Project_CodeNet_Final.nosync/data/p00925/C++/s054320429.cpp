#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){
  string s;
  ll t;
  cin>>s>>t;
  int n=s.size();
  ll sn[20];

  ll mf=0;
  for(int i=0;i<n;i++){
	if(s[i]=='+')sn[i]=0;
	else if(s[i]=='*')sn[i]=1;
	else sn[i]=s[i]-'0';
  }
  for(int i=0;i<n;i++){
	if(i%2&&sn[i]){
	  sn[i+1]=sn[i-1]*sn[i+1];
	  sn[i-1]=0;
	  sn[i]=0;
	}
  }
  for(int i=0;i<n;i++){
	mf+=sn[i];
  }

  ll ltr=s[0]-'0';
  for(int i=1;i<n;i+=2){
	if(s[i]=='+')ltr+=(ll)(s[i+1]-'0');
	else ltr*=(ll)(s[i+1]-'0');
  }

  if(t==mf&&t==ltr)cout<<"U"<<endl;
  else if(t==mf)cout<<"M"<<endl;
  else if(t==ltr)cout<<"L"<<endl;
  else cout<<"I"<<endl;
  
  return 0;
}

