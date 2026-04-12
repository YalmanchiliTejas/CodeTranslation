//@author rohit_0801

 
#include <bits/stdc++.h>
#define ll int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define debug 0
 
using namespace std;
const ll MOD = 1000000007;
const ll MODD = MOD-1;
 
ll ar[900780],has[1234567];

string strng[505];

vector<ll> vec,pec;

map<ll,ll> mark;

 
 
int main() {
	//srand(time(0));
	ll a,b,n,m,flag=0,r,t,u,v,w,x,y,z,k,res=0,d,maxm=-999999999,i,j,ct,h,ans=0,s,l,e,f,p,minm=999999999,c,type,q,len,siz,g;
 	
 	map<ll,ll>::iterator it,jt;
 	
 	string str="",ptr="";
 	char ch;
 	
 	cin>>n>>m;
 	
 	for(i=0;i<n;i++){
 		cin>>strng[i];
	 }
	 
	 for(i=0;i<n;i++){
	 	flag=0;
	 	ar[i]=0;
	 	for(j=0;j<m;j++){
	 		if(strng[i][j]!='.'){
	 			flag=1;
			 }
			 has[j]=0;
		 }
		 
		 if(flag==0){
		 	ar[i]=1;
		 }
	 }
	 
	 for(i=0;i<m;i++){
	 	flag=0;
	 	for(j=0;j<n;j++){
	 		if(strng[j][i]!='.'){
	 			flag=1;
			 }
		 }
		 
		 if(flag==0){
		 	has[i]=1;
		 }
	 }
	 
	 for(i=0;i<n;i++){
	 	if(ar[i]==0){
	 		for(j=0;j<m;j++){
	 			if(has[j]==0){
	 				cout<<strng[i][j];
				 }
		 	}
		 	cout<<"\n";
		}
	 	
	 }
 	
		
	return 0;
}  