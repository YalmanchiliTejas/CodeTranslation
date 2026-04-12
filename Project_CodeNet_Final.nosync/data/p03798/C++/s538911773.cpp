#include<bits/stdc++.h>
#define INF 1e9+7
#define ll long long
#define f(x) for(ull i=0;i<x;i++)
#define F first
#define S second
#define N 100005
#define M 1000000007
#define mp make_pair
#define ull unsigned long long
#define sc(n) scanf("%d",&n)
#define gcd __gcd
using namespace std;
int n;
map<char,char> in;
bool check(string &s,string &ans){

    for(int i=1;i<n-2;i++){
        if(s[i]=='o'){
            if(ans[i]=='S'){
                if(ans[i-1]!=ans[i+1])
                    ans[i+1]=ans[i-1];
            }
            else{
                if(ans[i-1]==ans[i+1])
                    ans[i+1]=in[ans[i-1]];
            }
        }
        else{
            if(ans[i]=='S'){
                if(ans[i-1]==ans[i+1])
                    ans[i+1]=in[ans[i-1]];
            }
            else{
                if(ans[i-1]!=ans[i+1])
                    ans[i+1]=ans[i-1];
            }
        }
    }
    int i=n-2,fn=0;
    if(s[n-2]=='o'&&ans[n-2]=='S'&&ans[i-1]==ans[i+1] || s[n-2]=='x'&&ans[n-2]=='S'&&ans[i-1]!=ans[i+1]
       ||s[n-2]=='o'&&ans[n-2]=='W'&&ans[i-1]!=ans[i+1]|| s[n-2]=='x'&&ans[n-2]=='W'&&ans[i-1]==ans[i+1] )
       fn=1;
    if(s[n-1]=='o'&&ans[n-1]=='S'&&ans[n-2]==ans[0] || s[n-1]=='x'&&ans[n-1]=='S'&&ans[n-2]!=ans[0]
       ||s[n-1]=='o'&&ans[n-1]=='W'&&ans[n-2]!=ans[0]|| s[n-1]=='x'&&ans[n-1]=='W'&&ans[n-2]==ans[0] ){
       if(fn){
        cout<<ans<<endl;
        return 1;
       }
    }
    return 0;
}
int main() {
	ios::sync_with_stdio(false);
    in['W']='S';
    in['S']='W';
    string s;
    cin>>n>>s;
    string ans(n,'S');
    if(s[0]=='x'){
        ans[n-1]='W';
        if(check(s,ans))
            return 0;
        ans[n-1]='S',ans[1]='W';
        if(check(s,ans))
            return 0;
        ans[0]='W';
        ans[n-1]='W';
        ans[1]='W';
        if(check(s,ans))
            return 0;
        ans[n-1]='S';
        ans[1]='S';
        if(check(s,ans))
            return 0;
    }
    else{
        ans[0]='W';
        ans[n-1]='W';
        ans[1]='S';
        if(check(s,ans)){
            return 0;
        }
        ans[n-1]='S';
        ans[1]='W';
        if(check(s,ans)){
            return 0;
        }
        ans[0]='S';
        ans[n-1]='W';
        ans[1]='W';
        if(check(s,ans))
            return 0;
        ans[n-1]='S';
        ans[1]='S';
        if(check(s,ans))
            return 0;
    }
    cout<<-1<<endl;
    return 0;
}
