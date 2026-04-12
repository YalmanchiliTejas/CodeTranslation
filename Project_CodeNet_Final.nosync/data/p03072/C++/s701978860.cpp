#include<bits/stdc++.h>
using namespace std;
int mas=-1;
int ans;
int main()
{
 int t;
 cin>>t;
 int all[t+1];
 for(int i=0;i<t;i++)
 {
 	cin>>all[i];
 }
 for(int i=0;i<t;i++)
 {
 	mas=max(mas,all[i]);
 	if(all[i]>=mas)
 	{
 		ans++;
	 }
 }
 cout<<ans<<endl; 
}