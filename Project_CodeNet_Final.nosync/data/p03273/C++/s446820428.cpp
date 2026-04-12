#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n;i>0;i--)
#define rep1(i,s,n) for(int i=s;i<n;i++)
#define max0(a,b,c) max(max(a,b),c)
#define min0(a,b,c) min(min(a,b),c) 
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

const int max_h=100,max_w=100;
int h,w;
char a[max_h+1][max_w+1];

void solve(){
    priority_queue<int,vector<int>,greater<int>> H,W;
    queue<int> que;
    bool flag=false;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#') break;
            else if(j==w-1 && a[i][j]!='#')
            H.push(i);
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(a[j][i]=='#') break;
            else if(j==h-1 && a[j][i]!='#')
            W.push(i);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!H.empty() || !W.empty()){
                if(i==H.top()){
                    H.pop();
                    flag=true;
                    break;
                }else if(j==W.top()){
                    que.push(W.top());
                    W.pop();
                }else cout << a[i][j];
            }else cout << a[i][j];
        }
        while(!que.empty()){
            W.push(que.front());
            que.pop();
        }
        if(!flag) cout << endl;
        else flag=false;
    }
}

int main(){
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    solve();
}