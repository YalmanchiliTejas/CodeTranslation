#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;


int main(){
  int n;
  while(1){
    cin>>n;
    if(n==0){
      break;
    }
    vector<int> s(n);
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
    sort(s.begin(),s.end());
    s.erase(s.end()-1);
    s.erase(s.begin());
    int sum=0,avg;
    for(int i=0;i<s.size();i++){
      sum+=s[i];
    }
    avg=sum/s.size();
    cout<<avg<<endl;
  }
  return 0;
}

