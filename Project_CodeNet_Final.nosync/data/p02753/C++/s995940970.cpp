#include<bits/stdc++.h>
using namespace std;
 
#define ll          long long int
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         100000000000001
#define MAXN        200005
#define mod         1000000007
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]){
        cout<<"No";
    }
    else{
        cout<<"Yes";
    }
}