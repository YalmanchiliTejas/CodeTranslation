#include <bits/stdc++.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;

int main(){
	IOS;
set<char> s;
string v;
cin>>v;
for(int i=0;i<3;i++)
s.insert(v[i]);
if(s.size()==2)
cout<<"Yes";
else 
cout<<"No";    
    
}