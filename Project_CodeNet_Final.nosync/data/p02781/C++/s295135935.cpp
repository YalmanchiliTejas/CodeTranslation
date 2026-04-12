#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
/************************************************/
#define rep(i,n) for(int i=0;i<n;i++)
#define m_p make_pair
#define pb push_back
#define fr first
#define se second
#define forn(i,a,n) for(int i=a;i<n;i++)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define sz(s) s.size()
#define all(s) s.begin(),s.end()
#define zero(x) memset(x,0,sizeof(x))
#define vii vector<pair<int,int> >
#define mpis map<int,string>
#define mpii map<int,int>
#define mpsi map<string,int>
#define re return
#define mod 1000000007
/************************************************/
using namespace std;

long long get(){
	char c=getchar();
	long long x=0LL;
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9'){
		x*=10LL;
		x+=(c-'0');
		c=getchar();
	}
	return x;
}
int dp[102][4][2];
string s;
int krk;
int main(){
	ios::sync_with_stdio(0);
    cin>>s>>krk;
    dp[0][0][0]=1;
    forn(i,0,sz(s)){
        forn(j,0,4){
            forn(k,0,2){
                int sd=s[i]-'0';
                forn(d,0,10){
                    int i1=i+1,j1=j,k1=k;
                    if(d)
					j1++;
                    if(j1>krk)
					break;
                    if(k==0){
                        if(d>sd)
						break;
                        if(d<sd)
						k1=1;
                    }
                    dp[i1][j1][k1]+=dp[i][j][k];
                }
            }
        }
    }
    cout<<dp[sz(s)][krk][0]+dp[sz(s)][krk][1];
	re 0;
}