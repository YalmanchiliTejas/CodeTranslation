#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;
typedef pair<int,int> P;
string s;
int k;
int INF=1000000000;
int dh[4]={0,1,0,-1};
int dw[4]={1,0,-1,0};

int main(){
    int n,m;cin>>n>>m;
    vector<int> v[n];
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int num[n];
    rep(i,0,n) num[i]=i;
    int count=0;
    do{
        bool flag=true;
        for(int now=0;now<n-1;now++){
            bool flag2=false;
            for(int i=0;i<v[num[now]].size();i++){
                if(num[now+1]==v[num[now]][i]){
                    flag2=true;
                    break;
                }
            }
            if(!flag2){
                flag=false;
                break;
            }
        }
        if(flag) count++;
    }while(next_permutation(num+1,num+n));
    cout<<count<<endl;
}