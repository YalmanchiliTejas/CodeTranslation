#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  string s;cin>>s;
  bool ans=false;
  for(int i=0;i<(int)s.size()-1;i++){
    if(s.substr(i, 2)=="AC"){ans=true;break;}
  }
  cout<<(ans?"Yes":"No")<<endl;
}