#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,i;
  cin >> n;
  vector<long long> a(n);
  
  for(i=0;i<n;i++){
    cin >> a.at(i);
  }
  
  if(n%2==0){
    long long s,m;
    s=0;
    for(i=0;i<=n/2-1;i++){
      s=s+a.at(i*2);
    }
    m=s;
    
    for(i=n/2-1;i>=0;i--){
      s=s-a.at(i*2)+a.at(i*2+1);
      m=max(m,s);
    }
    
    cout << m << endl;
    
  }else{
    vector<vector<long long>> s((n-1)/2,vector<long long>(3,0));
    s.at(0).at(0)=a.at(0);
    s.at(0).at(1)=a.at(1);
    s.at(0).at(2)=a.at(2);
    for(i=1;i<=(n-3)/2;i++){
      s.at(i).at(0)=s.at(i-1).at(0)+a.at(2*i);
      s.at(i).at(1)=max(s.at(i-1).at(0),s.at(i-1).at(1))+a.at(2*i+1);
      s.at(i).at(2)=max(max(s.at(i-1).at(0),s.at(i-1).at(1)),s.at(i-1).at(2))+a.at(2*i+2);
    }
    cout << max(s.at((n-3)/2).at(0),max(s.at((n-3)/2).at(1),s.at((n-3)/2).at(2))) << endl;
  }
}