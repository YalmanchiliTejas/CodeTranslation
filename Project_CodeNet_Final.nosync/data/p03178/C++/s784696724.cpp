#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long a[10005][102][2];
long long n,d,mod=1000000007;
string s;
long long ff(int i,int cnt,int tight){
if(i==n && cnt==0) return(1);
if(i==n) return(0);
if(a[i][cnt][tight] !=-1) return(a[i][cnt][tight]);
int end;
if(tight==0) end=9;
if(tight==1) end=s[i]-'0';
long long ans=0;
for(int j=0;j<=end;j++){
if(!tight){ans=ans+ff(i+1,(cnt+j)%d,tight);}
else{
if(j !=end) {ans=ans+ff(i+1,(cnt+j)%d,0);}
else {ans=ans+ff(i+1,(cnt+j)%d,1);}
}
}ans=ans%mod;
a[i][cnt][tight]=ans;
return(ans);
}
int main(){
long long ans;
int t,i;
memset(a,-1,sizeof(a));
cin>>s;n=s.size();cin>>d;
ans=(ff(0,0,1)-1+mod)%mod;
cout<<ans<<endl;

}