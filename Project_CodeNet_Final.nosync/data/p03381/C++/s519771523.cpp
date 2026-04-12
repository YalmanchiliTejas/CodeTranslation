
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
int n;
scanf("%d",&n);
int a[n];
vector<int >b(n);
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
b[i]=a[i];
}
sort(b.begin(),b.end());

for(int i=0;i<n;i++)
{
    if(a[i]<b[n/2])cout<<b[n/2]<<" ";
    else cout<<b[(n/2)-1]<<" ";
    
}

return 0;
}