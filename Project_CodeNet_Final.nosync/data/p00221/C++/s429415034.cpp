#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;int main(){int m,n,i;set<int> p;set<int>::iterator q;string s;stringstream t;while(cin>>m>>n,m|n){p.clear();for(i=1;i<=m;i++)p.insert(i);q=p.begin();for(i=1;i<=n;i++){cin>>s;if(p.size()==1)continue;t.str("");if(i%3&&i%5){t<<i;}else{if(!(i%3))t<<"Fizz";if(!(i%5))t<<"Buzz";}if(s!=t.str())p.erase(q++);else q++;if(q==p.end())q=p.begin();}for(q=p.begin();q!=p.end();q++){if(q!=p.begin())cout<<" ";cout<<*q;}cout<<endl;}}