#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
#include<string>
using namespace std;struct k{string s;int n;};bool x(const k&left,const k&right){return left.n>right.n;}int main(){vector<k> t;k c;int n,i=0,w,d;string s;while(cin>>n,n){if(i)cout<<endl;t.clear();for(i=0;i++<n;){cin>>s>>w>>d>>d;c.s=s;c.n=3*w+d;t.push_back(c);}sort(t.begin(),t.end(),x);for(i=0;i<n;i++)cout<<t[i].s<<","<<t[i].n<<endl;}return 0;}