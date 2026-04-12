#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

const int N = 1e6 + 69;

ll n,y,m;

string s,t,u;
ll ans = 0;

int main(){

    cin>>s>>m;
    n = s.size();
    if(m==1){
        ans += (n-1) * 9;
        ans += (s[0]-'0');
        cout<<ans<<endl;
    } else
    if(m==2){

        ans += (n-1)*(n-2)/2 * 81;

        ans += (n-1) * 9 * (s[0]-'0'-1);
        int x = 1;
        while(s[x]=='0' && x<n){
            x++;
        }
        n -= x;
        if(n<=0){
            cout<<ans<<endl;
            return 0;
        }

        ans += (n-1) * 9;
        ans += (s[x]-'0');

        cout<<ans<<endl;
    } else {

        ans += (n-1)*(n-2)*(n-3)/6 * 9 * 9 * 9;

        ans += (s[0]-'0'-1) * (n-1)*(n-2) / 2 * 81;

        int x = 1;
        while(s[x]=='0' && x<n){
            x++;
        }
        m = n;
        n -= x;
        if(n<=0){
            cout<<ans<<endl;
            return 0;
        }

        ans += (n-1)*(n-2)/2 * 81;

        ans += (n-1) * 9 * (s[x]-'0'-1);
        x++;
        while(s[x]=='0' && x<m){
            x++;
        }
        n = m - x;
        if(n<=0){
            cout<<ans<<endl;
            return 0;
        }

        ans += (n-1) * 9;
        ans += (s[x]-'0');

        cout<<ans<<endl;
    }
}
