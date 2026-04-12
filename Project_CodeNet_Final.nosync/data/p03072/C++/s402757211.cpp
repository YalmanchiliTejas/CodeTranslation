#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,j,k,max,ans; 
cin >>n;
max=0;
vector<int>  h(n);
for(i=0;i<n;i++)
{
cin >> h.at(i);
}
for(i=0;i<n;i++)
{
if(max<=h.at(i))
   {
    ans++;
     max=h.at(i);
   }
}
cout << ans <<endl;
}



