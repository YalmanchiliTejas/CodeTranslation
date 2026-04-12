#include<bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  long long int ans; cin>>ans;

  long long int m_rule=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='*'){
      long long int pro=s[i-1]-'0';
      for(i=i+2;i<s.size();i+=2){
	if(s[i]=='*'){
	  pro*=s[i-1]-'0';
	}
	else{
	  break;
	}
      }
      pro*=s[i-1]-'0';
      m_rule+=pro;
    }
  }
  if(s.size()==1) m_rule=s[0]-'0';
  if(s.size()>1  && s[1]=='+') m_rule+=s[0]-'0';
  if(s.size()>2 && s[s.size()-2]=='+') m_rule+=s[s.size()-1]-'0';
  for(int i=2;i+1<s.size();i++){
    if(s[i-1]=='+' && s[i+1]=='+'){
      m_rule+=s[i]-'0';
    }
  }

  long long int l_rule=s[0]-'0';
  for(int i=1;i<s.size();i+=2){
    if(s[i]=='+') l_rule+=s[i+1]-'0';
    else l_rule*=s[i+1]-'0';
  }

  if(l_rule==ans && m_rule==ans) cout<<"U"<<endl;
  else if(l_rule==ans) cout<<"L"<<endl;
  else if(m_rule==ans) cout<<"M"<<endl;
  else cout<<"I"<<endl;
  return 0;

}