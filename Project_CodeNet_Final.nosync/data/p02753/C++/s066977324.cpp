#include<bits/stdc++.h>
using namespace std;
int main(){
   string s;
   cin>>s;
   set<char>sat(s.begin(),s.end());
   if(sat.size()==2)cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
}