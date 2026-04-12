#include<iostream>
using namespace std;
#define df 0
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long int li;

li combin(int n,int r){
  if(n<r or r<0) return 0;
  int a=1;li s=1;
  rep(i,r){
    s*=n-a+1;
    s/=a;
    a++;
  }
  return s;
}
li pow9(int k){
  li s=1;
  rep(i,k){
    s*=9;
  }
  return s;
}

li f(int n,int k){
  return combin(n,k)*pow9(k);
}
int p(string st,int k){
  int s=0;
  for(auto x:st){
    if(x!='0') s++;
  }
  return s==k;
}

int main(){
  if(df) printf("*debug mode*\n");
  string st; cin >>st;
  int n=st.size();
  int k; cin>>k;
  li ans=0;  
  int i=0;
  if(df){
    rep(i,n){
      rep(j,3){
	printf("%ld ",f(i,j));
      }
      printf("\n");
    }
  }
  
  if(p(st,k))ans++;
  rep(i,n){
    if(k<0){break;}
    if(st.at(i)=='0') continue;
    ans+=f(n-i-1,k);
    ans+=f(n-i-1,k-1)*(st.at(i)-'0'-1);
    k--;
  }
  printf("%ld",ans);
}

/// confirm df==0 ///
