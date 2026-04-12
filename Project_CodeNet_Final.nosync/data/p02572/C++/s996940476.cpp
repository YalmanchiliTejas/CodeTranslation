    #include<bits/stdc++.h>
    using namespace std;
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define REP(i,x) for(int i=0;i<(int)(x);i++)
    #define REPS(i,x) for(int i=1;i<=(int)(x);i++)
    #define mp(a,b) make_pair(a, b)
    #define pb push_back
    #define eb emplace_back
    #define ll long long
    #define MAX 1000000007
    int main()
    { int t;
    cin>>t; int ar[t];
    ll s=0;
    for(int i=0;i<t;i++)
    {
        cin>>ar[i];
        s+=ar[i];
        s%=MAX;
    }ll a=0;
    for(int i=0;i<t-1;i++)
    {s=s-ar[i];
    if(s<0) s+=MAX;
        a+=(s)* ar[i];
        a%=MAX;
    }
    a%=MAX;
    cout<<a<<endl;
    }