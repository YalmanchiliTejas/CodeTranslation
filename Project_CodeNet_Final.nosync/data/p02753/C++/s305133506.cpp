#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
string s;
int count_a=0,count_b=0;
cin>>s;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='A')count_a++;
    else count_b++;
}
if(count_a && count_b)
cout<<"Yes"<<endl;
else cout<<"No"<<endl;


}