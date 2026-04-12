#include <bits/stdc++.h>
using namespace std;
string n;int A,k;
int g(int a,int b){A=6;while(b--)A*=(a-b)*9,A/=b+1;return A/6;}
int f(int i,int a){int A=n.size()-i;return (A<a?0:!a?1:n[i]=='0'?f(i+1,a):f(i+1,a-1)+(n[i]-'1')*g(A-1,a-1)+g(A-1,a));}
main(){cin>>n>>k;cout<<f(0,k);}
