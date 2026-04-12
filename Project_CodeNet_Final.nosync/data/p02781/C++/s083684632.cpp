#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int solve(string n,int k)
{
    if(k==0)
        return 1;
    reverse(n.begin(),n.end());
    while(!n.empty()&&n.back()=='0')
        n.pop_back();
    reverse(n.begin(),n.end());
    int s=n.size();
    if(s<k)
        return 0;
    int ans1;
    if(k==1)
        ans1=(s-1)*9;
    else if(k==2)
        ans1=(s-1)*(s-2)/2*9*9;
    else if(k==3)
        ans1=(s-1)*(s-2)*(s-3)/6*9*9*9;
    int ans2=solve(string(s-1,'9'),k-1)*(n[0]-'0'-1);
    int ans3=solve(n.substr(1),k-1);
    return ans1+ans2+ans3;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    int k;
    cin>>n>>k;
    cout<<solve(n,k);
}
