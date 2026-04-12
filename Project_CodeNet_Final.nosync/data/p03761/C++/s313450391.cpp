#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
using namespace std;
bool debug=false;

int main(){
  int n;
  string s,ans;
  cin>>n>>ans;
  for(int i=1;i<n;i++){
    string tmp;
    cin>>s;
    bool flag=true;
    while(flag){
      flag=false;
      for(int j=0;j<ans.size();j++){
	for(int k=0;k<s.size();k++){
	  if(ans[j]==s[k]){
	    tmp=tmp+ans[j];
	    ans.erase(ans.begin()+j);
	    s.erase(s.begin()+k);
	    flag=true;
	    //cout<<"debug: "<<ans<<" "<<s<<endl;
	  }
	}
      }
    }
    ans=tmp;
  }
  sort(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}
