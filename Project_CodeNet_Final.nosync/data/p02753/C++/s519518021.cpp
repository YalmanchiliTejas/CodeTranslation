#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,i,e,f,g,n,m,k,l,j,A[500005],t;
string s;  
int main() {
           cin>>s;
           for(long long i=0;i<s.size();i++) {
                      if(s[i]=='A') a=1;
                      else b=1;
           }
           if(a==1 && b==1) cout<<"Yes";
           else cout<<"No";
}