#include <bits/stdc++.h>
using namespace std;
# define ll long long int
#define M 1000000007
#define ff first
#define ss second
#define pb push_back  
#define INF 10000000000

 

 int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   ll i,f,ss,th,ans = 0,k,t,j;
   string s;
   cin>>s>>k;
  
   ll n = s.length();
    f = n+5;
   ss= n+5;th = n+5;
   t = 0;
   for(i=0;i<n;i++){
   	if(s[i] != '0' && t == 0){
   		f = i;
   		t++;
   		continue;
	   }
	   if(s[i] != '0' && t == 1){
   		ss = i;
   		t++;
   		continue;
	   }
	   if(s[i] != '0' && t == 2){
   		th = i;
   		t++;
   		continue;
	   }
   }
   
   if(k == 1){
   	for(i=0;i<n;i++){
   		
   		if(i == f){
   			ans += s[i] - '0';
		   }else if(i > f){
		   	ans+=9;
		   }
	   }
   }else if( k == 2){
	   	 for(i=0;i<n;i++){
		   	for(j=i+1;j<n;j++){
		   		if(i < f)	continue;
		   		if(i == f){
		   			if(j < ss)	ans += (s[f] - '0' -1)*9;
		   			if(j == ss )	ans+=(s[f]-'0'-1)*9 + s[ss] - '0';
		   			if(j > ss)	ans+=(s[f]-'0')*9 ;
				   }
				   if(i > f){
				   	ans += 9*9;
				   }
			   }
	   }
   }
   else{
   		for(i=0;i<n;i++){
		   	for(j=i+1;j<n;j++){
		   		for(k=j+1;k<n;k++){
		   				if(i < f)	continue;
				   		if(i == f){
				   			if(j < ss)	ans += (s[f]-'0'-1) * 9*9;
				   			if(j == ss){
				   				if(k < th)	ans += (s[f]-'0'-1)*9*9 + (s[ss]-'0'-1)*9;
				   				if(k == th)	ans += (s[f]-'0'-1)*9*9 + (s[ss]-'0'-1)*9 + s[th]-'0';
				   				if(k > th)	ans += (s[f]-'0'-1)*9*9 + (s[ss]-'0')*9;
							   }
							   if(j > ss){
							   	ans += (s[f]-'0')*9*9 ;
							   }
						   }
						   if(i > f){
						   	ans += 9*9*9;
						   }
				   }
			   }
   }
   }
   
   cout<<ans;
   
}