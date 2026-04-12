#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=1e5+5,mod=1e9+7;
typedef long long ll;
ll n,ans;
map<int,ll>mp;
int main()
{
    Elhabashy
    input();

    cin>>n;
    cout<<(n>=30?"Yes":"No");

}
