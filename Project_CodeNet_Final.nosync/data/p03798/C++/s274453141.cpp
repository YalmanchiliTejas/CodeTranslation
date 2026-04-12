#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

ll n;
string s;
bool can=true;
char ans[100010];
void sw(){
    rep2(i,1,n-2){
        if(ans[i]=='S'){
            if(s[i]=='o') ans[i+1]=ans[i-1];
            else{
                if(ans[i-1]=='S') ans[i+1]='W';
                else ans[i+1]='S';
            }
        }
        else{
            if(s[i]=='x') ans[i+1]=ans[i-1];
            else{
                if(ans[i-1]=='S') ans[i+1]='W';
                else ans[i+1]='S';
            }
        }
    }
    rep2(i,n-2,n){
        if(s[i]=='o'){
            if(ans[i]=='S'){
                if(ans[i-1]!=ans[i+1]){
                    can=false;
                    break;
                }
            } else{
                if(ans[i-1]==ans[i+1]){
                    can=false;
                    break;
                }
            }
        } else{
            if(ans[i]=='S'){
                if(ans[i-1]==ans[i+1]){
                    can=false;
                    break;
                }
            } else{
                if(ans[i-1]!=ans[i+1]){
                    can=false;
                    break;
                }
            }
        }
    }
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>s;
    ans[0]='S';
    if(s[0]=='o'){
        can=true;
        ans[1]='S';ans[n-1]='S';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
        can=true;
        ans[1]='W';ans[n-1]='W';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
    } 
    else{
        can=true;
        ans[1]='S';ans[n-1]='W';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
        can=true;
        ans[1]='W';ans[n-1]='S';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
    }

    ans[0]='W';
    if(s[0]=='o'){
        can=true;
        ans[1]='S';ans[n-1]='W';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
        can=true;
        ans[1]='W';ans[n-1]='S';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
    } 
    else{
        can=true;
        ans[1]='S';ans[n-1]='S';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
        can=true;
        ans[1]='W';ans[n-1]='W';ans[n]=ans[0];
        sw();
        if(can){
            rep(i,n){
                cout<<ans[i];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}