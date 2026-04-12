#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
typedef pair<int,int> P;
int a,b,cnt,n;
char ch;
vector < P > t;
int ans[1000];
int main(){
  cnt=0;
  while(cin>>a>>ch>>b){
    if(a==0&&b==0)break;
    t.push_back(P(b,a));
    cnt++;
  }
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  


  ans[0]=1;
  for(int i=1;i<cnt;i++){
    if(t[i].first==t[i-1].first)ans[i]=ans[i-1];
    else ans[i]=ans[i-1]+1;
  }
  while(cin>>n){
    for(int i=0;i<cnt;i++){
      if(t[i].second==n){
	cout<<ans[i]<<endl;
	break;
      }
    }
  }
  return 0;
}