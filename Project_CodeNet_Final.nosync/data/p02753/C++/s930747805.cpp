#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define graph vector< vector<int> >
#define vs vector<string>
#define mn -
#define mod %
#define E =
#define EE ==
int mx=9999999;
/**  '' "\n" - ^ **/

void yes()
{
    cout<<"Yes\n";
}

void no()
{
    cout<<"No\n";
}
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void bin(int n)
{
    cout<<n<<endl;
    while(n>0)
    {
        cout<<n%2;
        n/=2;
    }
}
int main() {
    string str;
    cin>>str;
    if(str.length()==1)
    {
        cout<<"No\n";
    }

    else if(str.length()==2)
    {
        if(str[0]!=str[1])
            cout<<"Yes\n";
        else
        cout<<"No\n";
    }

    else
    {
        if(str[0]!=str[1]||str[1]!=str[2])
            cout<<"Yes\n";
        else
        cout<<"No\n";
    }
}
