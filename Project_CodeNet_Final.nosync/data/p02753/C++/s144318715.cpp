#include<bits/stdc++.h> 
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ifor(n) for(int i=0;i<n;i++) 
#define jfor(n) for(int j=0;j<n;j++)
#define Ifor(n) for(int i=1;i<n;i++) 
#define Jfor(n) for(int j=1;j<n;j++)
const int inf=0x3f3f3f3f;
int main(){
	char s[3];
	scanf("%s",&s);
	int a=0;
	ifor(3){
		if(s[i]=='A')a++;
	}
	if(a==0||a==3)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
} 