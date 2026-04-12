//Radhe Radhe
#include<bits/stdc++.h>//157B
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
using namespace std;

int main()
{
    ll i,j,n,k;
    char key;
    string s;
    cin>>n>>s>>k;
    key=s[k-1];
    for(i=0;s[i];i++)
    {
        if(key!=s[i])
        cout<<"*";
        else cout<<s[i];

    }

    cout<<endl;



    return 0;
}



