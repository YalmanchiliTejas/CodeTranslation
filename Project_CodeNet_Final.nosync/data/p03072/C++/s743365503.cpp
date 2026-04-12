#include <bits/stdc++.h>
#include<algorithm>
#include<deque>
using namespace std;

#include<cstdio>
#define r(i,n) for(int i=0;i<n;i++)


int main(void){
 int n;
 cin>>n;
 int maxi=0,cnt=0;
 vector<int> h(n);
 r(i,n){
   cin>>h.at(i);
   if(maxi<=h.at(i))cnt++;
   maxi=max(maxi,h.at(i));
 }

 cout<<cnt<<endl;

return 0;}
