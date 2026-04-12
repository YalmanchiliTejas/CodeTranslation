#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
while(1){ 
cin>>n;
if(!n) break;
vector<int> v(n);

int sum=0;
 for(int i=0;i<n;++i){
cin>>v[i];
}
sort(begin(v),end(v));
for(int i=1;i<n-1;++i){
sum+=v[i];}
cout<<sum/(n-2)<<endl;
}}