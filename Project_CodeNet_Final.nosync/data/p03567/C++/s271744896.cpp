#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  string s;
  while(cin>>s){
    bool l=0;
    for(int i=0; i+1<s.size(); ++i){
      if(s[i]=='A'&&s[i+1]=='C')
        l=1;
    }
    if(l)
      cout<<"Yes"<<endl;
    else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}

