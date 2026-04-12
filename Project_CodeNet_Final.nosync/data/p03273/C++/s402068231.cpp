#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    map<ll,ll>x,y;
    cin>>h>>w;
    char l1[h+1][w+1];
    for(int i=1;i<=h;i++){ll a=0,b=0;
        for(int j=1;j<=w;j++){
            cin>>l1[i][j];
            if(l1[i][j]=='.')x[i]++,y[j]++;
        }
    }
    for(int i=1;i<=h;i++){ll a=0,b=0;
        for(int j=1;j<=w;j++){
            if(x[i]==w)break;
            if(y[j]!=h)cout<<l1[i][j];
        }if(x[i]!=w)cout<<endl;
    }
}
