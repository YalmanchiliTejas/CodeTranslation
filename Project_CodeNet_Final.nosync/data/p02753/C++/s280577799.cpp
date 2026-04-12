#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define F(i,a,b) for(int i=a;i<b;i++)
#define RF(i,a,b) for(int i=a;i>b;i--)
#define mp(a,b) make_pair(int a,int b)
#define ll long long
const int mxn=1e3+10,mxm=4e5+10,modl=1e9+7;
int nm,n,m,p,t,ans,sum;
int a[mxn],b[mxn],h[mxn];
//string s[mxn];
//bool in[mxn][mxn];
//int tr[][2]={{0,-1},{-1,0},{0,+1}};
//struct pos{
//    int x,y;
//    bool operator < (const pos b)const{
//        return h[x][y]>h[b.x][b.y];
//    }
//};
bool cmp(string a,string b){
    return a+b<b+a;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
//    cin>>nm;
    string s,s2;
    while(cin>>s){
//        priority_queue<int,vector<int>,greater<int>>q;
        if(s=="AAA"||s=="BBB") cout<<"No";
        else cout<<"Yes";
        //cout<<t;
        cout<<endl;
    }
    return 0;
}
