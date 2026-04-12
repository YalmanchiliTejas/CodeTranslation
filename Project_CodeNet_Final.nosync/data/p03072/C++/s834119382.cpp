#include <bits/stdc++.h>
using namespace std;

int main()
{ //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
int  n;
cin>>n;
 int ans,ma=0;
 cin>>ans;
 int count=1;
 for(int i=1;i<n;i++){
 	cin>>ma;
 	if(ma>=ans)
 	 count++,ans=ma;
 }
 cout<<count;
}
