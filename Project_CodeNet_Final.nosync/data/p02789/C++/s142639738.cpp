#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define deb(x) cout<<#x<<" : "<<x<<endl;
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    cout<<(n==m?"Yes":"No");

}