#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

int a[100005];//動物の正体　0羊　１狼

int main(){
    int n;
    cin >> n;
    string s;
    cin>> s;
    rep(p,2){
        rep(q,2){
            a[1]=p;
            a[2]=q;
            //a[0]
            if(a[1]==0){
                if(s[0]=='o'){
                    a[0]=a[2];
                }else{
                    if(a[2]==0){
                        a[0]=1;
                    }else{
                        a[0]=0;
                    }
                }
            }else{
                if(s[0]=='o'){
                    if(a[2]==0){
                        a[0]=1;
                    }else{
                        a[0]=0;
                    }
                }else{
                    a[0]=a[2];
                }
            }
            rep2(i,n-1){
                if(a[i]==0&&a[i+1]==0){
                    if(s[i]=='o'){
                        a[i+2]=0;
                    }else{
                        a[i+2]=1;
                    }
                }else if(a[i]==0&&a[i+1]==1){
                    if(s[i]=='o'){
                        a[i+2]=1;
                    }else{
                        a[i+2]=0;
                    }
                }else if(a[i]==1&&a[i+1]==0){
                    if(s[i]=='o'){
                        a[i+2]=1;
                    }else{
                        a[i+2]=0;
                    }
                }else if(a[i]==1&&a[i+1]==1){
                    if(s[i]=='o'){
                        a[i+2]=0;
                    }else{
                        a[i+2]=1;
                    }
                }
            }
            if(a[1]==a[n+1]&&a[0]==a[n]){
                rep2(i,n){
                    if(a[i]==0){
                        cout<<'S';
                    }else{
                        cout<<'W';
                    }
                }
                //cerr<<a[1]<<a[n+1]<<endl;
                //cerr<<s[1]<<endl;
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}