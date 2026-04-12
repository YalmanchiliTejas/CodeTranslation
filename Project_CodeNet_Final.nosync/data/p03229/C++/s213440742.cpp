#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long int> vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
  }
  
  if(n%2==0){
    vector<long long int> before(n/2);
    vector<long long int> after(n/2);
    sort(vec.begin(),vec.end());
    
    for(int i=0;i<n/2;i++){
     before.at(i)=vec.at(i);
    }
    for(int i=0;i<n/2;i++){
     after.at(i)=vec.at(i+n/2);
    }
    
    
    reverse(before.begin(),before.end());
    reverse(after.begin(),after.end());
    
    long long int answer=0;
    for(int i=0;i<n/2-1;i++){
      answer+=abs(after.at(i)-before.at(i))+abs(after.at(i)-before.at(i+1));
    }
    answer+=abs(after.at(n/2-1)-before.at(n/2-1));
    cout<<answer<<endl;
  }
  
  else{
    vector<long long int> before(n/2);
    vector<long long int> after(n/2+1);
    
    vector<long long int> beforef(n/2+1);
    vector<long long int> afterf(n/2);
    sort(vec.begin(),vec.end());
    
    for(int i=0;i<n/2;i++){
     before.at(i)=vec.at(i);
    }
    for(int i=0;i<n/2+1;i++){
     after.at(i)=vec.at(i+n/2);
    }
    
    for(int i=0;i<n/2+1;i++){
     beforef.at(i)=vec.at(i);
    }
    for(int i=0;i<n/2;i++){
     afterf.at(i)=vec.at(i+n/2+1);
    }
    
    long long int u;
    u=after.at(1);
    after.at(1)=after.at(n/2);
    after.at(n/2)=u;
    
    u=beforef.at(0);
    beforef.at(0)=beforef.at(n/2-1);
    beforef.at(n/2-1)=u;
    
    long long int p=0,q=0;
    
    for(int i=0;i<n/2;i++){
      p+=abs(before.at(i)-after.at(i))+abs(before.at(i)-after.at(i+1));
    }
    for(int i=0;i<n/2;i++){
      q+=abs(afterf.at(i)-beforef.at(i))+abs(afterf.at(i)-beforef.at(i+1));
    }
    
    cout<<max(p,q)<<endl;
    
  }
    
}