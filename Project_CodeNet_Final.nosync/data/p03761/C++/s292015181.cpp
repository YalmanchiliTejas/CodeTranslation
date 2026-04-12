#include<bits/stdc++.h>  
using namespace std;
int n;  
int f[130];  
int a[130];  
string st;  
int main()
{
    cin>>n; 
    memset(f,127,sizeof(f));  
    for(int i=1; i<=n; i++)
    {
        cin>>st;  
        memset(a,0,sizeof(a)); 
        for(int j=0; j<st.size(); j++) 
        a[st[j]]++;  
        for(int j=97; j<=122; j++)
        f[j]=min(a[j],f[j]); 
    }
    for(int i=97; i<=122; i++) 
    {
        for(int j=1; j<=f[i]; j++)  
        cout<<char(i);  
    }
    return 0;
}