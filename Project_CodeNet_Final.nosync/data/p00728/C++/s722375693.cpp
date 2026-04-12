#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
while(cin>>n){

if(n==0){break;}
int s[10000];
int al=0;
int mx=0;
int mi=10000;

for(int i=0;i<n;i++){
cin>>s[i];
al+=s[i];
mx=max(mx,s[i]);
mi=min(mi,s[i]);
}

al=(al-mx-mi)/(n-2);
cout<<al<<endl;
}



return 0;
}
