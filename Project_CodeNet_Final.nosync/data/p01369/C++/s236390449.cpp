#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<string>
using namespace std;

#define ll long long int
#define ld long double
#define reps(i,f,n) for(int i=f;i<n;i++)
#define rep(i,n) reps(i,0,n)
#define m1 cout<<"move1"<<endl
#define m2 cout<<"move2"<<endl
#define m3 cout<<"move3"<<endl
#define m4 cout<<"move4"<<endl

bool lr(char c){
  if(c<=103 || ( c>=113 && c<= 116) || (c >= 118 && c<=120) || c == 'z')
    return true;
  else
    return false;
}


int main(){
  string s;

  while(cin>>s,s[0] != '#'){
    //ll num = strlen(s);
    ll ans = 0;
    bool flag = true;

    flag = lr(s[0]);

    reps(i,1,s.size()){
      if(lr(s[i]) != flag){
	  ans++;
	  flag = lr(s[i]);
	}
    }
    cout<<ans<<endl;
  }
  return 0;
}
	
	  
    
    
    
    
    