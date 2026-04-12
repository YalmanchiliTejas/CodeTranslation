#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
using namespace std;

main()
{
        int n; cin>>n;
        string s; cin>>s;
        int k; cin>>k;
        char x=s[k-1];
        each(it,s)
        {
                if(it==x)continue;
                it='*';
        }
        cout<<s<<endl;
}