#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

#define mx 500008

#define pii pair<int,int>
#define pi acos(-1.0)
#define pb push_back
#define ss second
#define ff first
typedef long long int ll;
///adjacent move
int fx[4]={0,+1,0,-1};
int fy[4]={+1,0,-1,0};
///knight
ll prime[mx];

vector<pii>v[mx];
int main()
{
    int t=1;

    while(t--){
        ll n;
        cin>>n;
        if(n<30) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
