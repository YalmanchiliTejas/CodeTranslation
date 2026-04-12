#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,s3,s4;
    long long n,i,j,k,l,m;
    vector<string >vc;
    cin>>n;
    cin.ignore();
    for(i=0; i<n; i++)
    {
        cin>>s1;
        vc.push_back(s1);
    }
    if(vc.size()%2==0)
    {

        for(i=vc.size()-1; i>=1; i-=2)
        {
            cout<<vc[i]<<" ";
        }
        for(i=0;i<vc.size();i+=2)
        {
            cout<<vc[i]<<" ";
        }
    }
    else
    {
        for(i=vc.size()-1; i>=0; i-=2)
        {
            cout<<vc[i]<<" ";
        }
        for(i=1;i<vc.size();i+=2)
        {
            cout<<vc[i]<<" ";
        }

    }

    cout<<endl;
    return 0;
}
