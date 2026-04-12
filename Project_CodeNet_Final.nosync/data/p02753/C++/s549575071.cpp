#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
using namespace std;
int main(){
    char s[3];
    for(int i=0; i<3; i++)cin>>s[i];
    sort(s, s+3);
    if(s[0]==s[2])cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}