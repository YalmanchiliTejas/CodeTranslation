#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
 
int32_t main(){
    string s;
    cin>>s;
    int n=s.length();
    char ch=s[0];
    int flag=0;
    for(int i=1;i<n;i++){
        if(ch!=s[i]) {
            flag=1;
            break;
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}