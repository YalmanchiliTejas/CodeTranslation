#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define pb(in,tmp) in.push_back(tmp)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) loop(i,0,b)
#define all(in) in.begin(),in.end()
using namespace std;
int main(){
int n;
while(cin>>n,n){
vector<int>in;
rep(i,n){
int tmp;
cin>>tmp;
pb(in,tmp);
}
sort(all(in));
int sum=0;
loop(i,1,in.size()-1)sum+=in[i];
cout<<(int)(sum/(n-2))<<endl;
}
}