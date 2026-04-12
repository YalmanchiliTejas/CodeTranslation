#include<bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    Fast;
    long long t,n,m,i,j,k,x=0,y=0,z;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A'){
            x=1;
        }
        if(s[i]=='B'){
            y=1;
        }
    }
    if(x==1 && y==1)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

}
