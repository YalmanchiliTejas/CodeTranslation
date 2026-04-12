#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s[0]==s[2])
    {
     cout<<"No"<<endl;
    }
    else{
       cout<<"Yes"<<endl;
    }


    return 0;


}
