#include <bits/stdc++.h>
#define r(i,n) for(long long i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int counter(string s,int k){
  int saisyo=s[0]-'0',leng=s.size();
  int firstzero=1;
  while(firstzero<leng&&s[firstzero]=='0')firstzero++;
  if(leng==1&&k>1)return 0;
  else if(leng==1&&k==1)return saisyo;
  else if(leng==2&&k>2)return 0;
  else if(k==1){
    int ans=0;
    ans+=(leng-1)*9;
    ans+=saisyo;
    return ans;
  }
  else if(k==2){
    int ans=0;
    ans+=81*(leng-1)*(leng-2)/2;
    ans+=(saisyo-1)*(leng-1)*9;
    if(firstzero!=leng){
    ans+=(s[firstzero]-'0');
    ans+=(leng-firstzero-1)*9;
    }
    return ans;
  }
  else{
    int ans=0;
    ans+=243*(leng-1)*(leng-2)*(leng-3)/2;//最初の桁は０
    ans+=(saisyo-1)*81*(leng-1)*(leng-2)/2;//最初の桁は１～saisyo未満
    if(firstzero==leng)return ans;
    string s2=s.substr(firstzero,leng-firstzero);
    return ans+counter(s2,k-1);
  }
}

int main() {
  string s;
  cin >> s;
  int k;
  cin >>k;
  
  cout<<counter(s,k)<<endl;
}