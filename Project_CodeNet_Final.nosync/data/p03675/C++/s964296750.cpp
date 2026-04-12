#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ins(a,b,c) a.insert(a.begin()+b,c)
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
 int wari(int a,int b) {
   if(a%b==0)
     return a/b;
   else
     return a/b+1;
 }
 int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
 }
 int souwa(int a){
  return a*(a+1)/2;
 }
 int lcm(int a,int b){
  int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return d*e/f;
    }
  int gcm(int a,int b){
      int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return f;
  }
 bool prime(int a){
   if(a<2)
     return false;
   else if(a==2)
     return true;
   else if(a%2==0)
     return false;
   double b=sqrt(a);
    for(int i=3;i<=b;i+=2){
      if(a%i==0){
        return false;
      }
    }
   return true;
 }
signed main(){
  int a;
  cin>>a;
  vector<int> b(a),c;
  fo(i,a)
    cin>>b[i];
  for(int i=b.size()-1;i>=0;i-=2)
    c.push_back(b[i]);
  if(a%2==0){
  for(int i=0;i<b.size();i+=2)
    c.push_back(b[i]);
  }
  else{
    for(int i=1;i<b.size();i+=2)
    c.push_back(b[i]);
  }
  fo(i,a){
    cout<<c[i];
    if(i==a-1)
      cout<<endl;
    else
      cout<<' ';
  }
}