#include <iostream>
#include<bits/stdc++.h>
using namespace std;

# define ll long long 

const int md = 1e9+7;

int main() {
    ll n;
    cin>>n;

    vector<ll> v(n);
    vector<ll> pos(n+1,0);

    for(int i=0;i<n;i++)
    {
    	cin>>v[i];
    }

    for(int i=n-1;i>=0;i--)
    {
    	pos[i]=((pos[i+1]%md) + (v[i]%md))%md;
    }

    // for(int i=0;i<n;i++)
    // {
    // 	cout<<pos[i]<<" "<<endl;
    // }

    ll sum=0;
    for(int i=0;i<n-1;i++)
    {
    	sum = (((v[i]%md)*(pos[i+1]%md))%md + (sum%md))%md;

    }

    cout<<sum<<endl;

  return 0;
}