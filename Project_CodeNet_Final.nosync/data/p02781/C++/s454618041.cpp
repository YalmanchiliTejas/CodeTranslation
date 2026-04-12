#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
  int n,m,k,i,j;
  long long f,t,u=0,res;
  string s;
  cin >> s >> k;
  n=s.size();
  j=n;
  if(k==1){
    f=stoi(s.substr(0,1));
    res=9*(n-1)+f;
  }else if(k==2){
    f=stoi(s.substr(0,1));
    for(i=1;i<n;i++){
      t=stoi(s.substr(i,1));
      if(t>0) break;
    }
    res=81*(n-1)*(n-2)/2+(f-1)*9*(n-1)+t+9*max(n-i-1,0);
  }else{
    f=stoi(s.substr(0,1));
    for(i=1;i<n;i++){
      t=stoi(s.substr(i,1));
      if(t>0)
        if(u==0){
          u=t;
          j=i;
        }else{
          break;
        }
    }
    res=729*(n-1)*(n-2)*(n-3)/6+(f-1)*81*(n-1)*(n-2)/2;
    m=max(n-j,1);
    res+=81*(m-1)*(m-2)/2+(u-1)*9*(m-1)+t+9*max(n-i-1,0);
  }
  cout << res << endl;
  return 0;
}