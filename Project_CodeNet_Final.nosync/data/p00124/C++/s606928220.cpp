#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
string str[10];
P t[10];
int n=-1,a,b,c;
int main(){
  cin>>n;
  while(1){
    if(n==0)break;
    for(int i=0;i<n;i++){
      cin>>str[i]>>a>>b>>c;
      t[i].first=(a*3+c)*-1;
      t[i].second=i;
    }
    sort(t,t+n);
    
    for(int i=0;i<n;i++){
      cout<<str[t[i].second]<<','<<t[i].first*-1<<endl;
    }
    cin>>n;
    if(n==0)break;
    cout<<endl;
  }
  return 0;
}