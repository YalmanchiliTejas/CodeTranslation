#include<bits/stdc++.h>
using namespace std;int main(){string a;cin>>a;int b=0;for(int i=0;i<a.size();i++){if(a[i]=='C'&&a[i-1]=='A'){b++;}else{}}if(b==0){cout<<"No"<<endl;}else{cout<<"Yes"<<endl;}}