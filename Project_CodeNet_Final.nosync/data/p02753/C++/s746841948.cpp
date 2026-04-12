#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define nl "\n"
#define input for(ll i=0;i<n;i++)  cin>>a[i];
#define M 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>str;
    int a=0,b=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='A')
            a++;
        else
            b++;
            
    }
    if(a==0||b==0)
        cout<<"No"<<nl;
    else
        cout<<"Yes"<<nl;
}
