#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
const int N=2e5+3;
string s,p;
//vector<int>v;
//map<int,int>mp;

int main()
{
    ft
    ll t,i,j,n,m,l,r;
    s="aeiou";
    char c;
    cin>>c;
    for(char cc:s)
    {
        if(c==cc)
        {
            cout<<"vowel\n";
            return 0;
        }
    }
    cout<<"consonant\n";
    return 0;
}

