/*
Author:Fuad Ashraful Mehmet
University of Asia Pacific
Date:23 Feb 2020
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+5;
int n;

int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    bool flag=false;
    string s;cin>>s;
    for(int i=0;i<2;++i)
    {
        if(s[i]!=s[i+1])flag=true;
    }

    flag==true?cout<<"Yes"<<endl:cout<<"No"<<endl;
 return 0;
}