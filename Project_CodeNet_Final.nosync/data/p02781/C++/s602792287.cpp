#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, a, b) for(int i=a; i<b; i++)
#define per(i, a, b) for(int i=b-1; i>=a; i--)
#define ifor(n) for(int i=0;i<n;i++) 
#define jfor(n) for(int j=0;j<n;j++)
#define Ifor(n) for(int i=1;i<n;i++) 
#define Jfor(n) for(int j=1;j<n;j++)
const int inf=0x3f3f3f3f;
char s[104];
int main(){
   scanf("%s",&s);
   int n=strlen(s),k;
   cin>>k;
   ll sum=0;
   if(k==1){
   	   sum=(n-1)*9;
   	   int a=s[0]-'0';
   	   sum+=a;
   	   cout<<sum<<endl;
   }
   else if(k==2){
   	  int a=s[0]-'0'-1;
   	  sum+=(n-2)*(n-1)/2*9*9;
   	  sum+=(n-1)*9*a;
   	  Ifor(n){
   	  	if(s[i]!='0'){
   	  		int q=n-i;
   	  		sum+=(q-1)*9;
   	  		a=s[i]-'0';
   	  		sum+=a;
   	  		break;
		}
	  }
	  cout<<sum<<endl;
   }
   else{
   	   int a=s[0]-'0'-1;
   	   sum+=(n-1)*(n-2)*(n-3)/6*9*9*9;
   	   sum+=a*(n-2)*(n-1)/2*9*9;
   	   Ifor(n){
   	   	   if(s[i]!='0'){
   	   	   	a=s[i]-'0'-1;
			int q=n-i;	 
			sum+=(q-2)*(q-1)/2*9*9;
   	        sum+=(q-1)*9*a;
   	          for(int j=i+1;j<n;j++){
   	          	   if(s[j]!='0'){
   	          	   	 q=n-j;
   	  		        sum+=(q-1)*9;
   	  		        a=s[j]-'0';
   	  		        sum+=a;
   	  		        break;
					}
				 }
		    break;		 
			}
		}
		cout<<sum<<endl;
   }
}
