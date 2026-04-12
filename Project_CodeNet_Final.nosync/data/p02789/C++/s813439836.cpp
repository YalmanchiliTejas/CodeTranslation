#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ctoi(x) x-'0'
#define pshb(a) cin >> x;a.push_back(x)
#define fr(i,n) for(ll i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int a ,b  ;
    cin>>a>>b ;
    if (a>b)
        cout<<"No"  ;
    else
        cout<<"Yes" ;
}


