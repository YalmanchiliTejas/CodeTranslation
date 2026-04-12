#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,s;
  vector<int> ss;
  while(1){
    cin>>n;
    //    cout<<"::"<<n<<endl;
    if(n==0)break;
    ss.clear();
    int i,j,k;
    for(i=0;i<n;i++){
      cin>>s;
      ss.push_back(s);
    }
    sort(ss.begin(),ss.end());
    int re=0;
    for(i=1;i<ss.size()-1;i++)
      re+=ss[i];
    re/=ss.size()-2;
    cout<<re<<endl;
  }
  return 0;
}