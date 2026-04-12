//BISMILLAHIR-RAH-MANIR-RAHIM.
//ABU AYUB MD AHMADUL(CEO-PEREGRINE SPHERE).
//FORMER CEO-SPACEH(2019).
//DEPT.OF CSE,SUST//2018-19.
//------------------------------------------\\
//PRE-CODE========>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<math.h>
#include<numeric>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#define mp make_pair
#define ins insert
#define lli long long int
#define ll long long
#define pb push_back
#define loop1(i,l,n) for(i=l;i<=n;i++)
#define loop0(i,l,n) for(i=l;i<n;i++)
#define inf (1<<28)
#define pi 3.1415926536
const int MAX=1e6+9;
set<int>ist;
map<string,int>msi;
map<string,string>mss;
map<int,string>mis;
map<int,int>mii;
pair<int,int>pii;
vector<int>v;
vector<pair<int,int> >vv;
int cc[]= {1,-1,0,0};
int rr[]= {0,0,1,-1};
//BIPARTITE GRAPH FUCTION========>
/*
int cnt[2];
int vertices[MAX];
void Bipartite(int node,int pnode,int color)
{
    cnt[color]++;
    for (int i=0;i<vertices[node].size();i++)
    {
        if (vertices[node][i]!=pnode)
        {
            Bipartite(vertices[node][i],node,!color);
        }

    }
}
*/
//REAL TIME BINARY SERACH FUNCTION========>
/*
int Bsearch(int left,int right,int query,int n)
{
    int mid=left+(right-left)/2;
    if(query<mid)
    {
        return Bsearch(left,mid-1,query,n);
    }
    else if(query>mid)
    {
        return Bsearch(mid+1,right,query,n-1);
    }
    else
    {
        return n;
    }
}
*/
//DECIMAL TO BINARY DECODING========>
/*
ll D2B(ll dec)
{
    ll digit[32]={};
    ll i = 0;
    while (dec > 0)
    {
        [i] = n % 2;
        n = n / 2;
        i++;
    }

}
*/
//BINARY TO DECIMAL DECODING========>
/*
ll b2d(ll bin)
{
    ll digit,sum=0,h=0;
    while(bin!=0)
    {
        digit=bin%10;
        sum+=digit*pow(2,h++);
        bin/=10;
    }
    return sum;
}
*/
//DFS FUNCTION=========>
/*
int visited[MAX];
vector<int>adj[MAX];
int weight[MAX];
void dfs(int v)
{
    visited[v] = 1;
    for (auto j: adj[v])
    {
        if (!visited[j])
        {
            dfs(j);
        }
    }
}
*/
//------------------------------------------\\
//LAUNCHING SHARK-20========>
void BACKSLASH()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    int n;
    cin>>n;
    if(n>=30)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

}
//MAIN FUNCTION========>
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    BACKSLASH();

    return 0;
}
//------------------------------------------\\
//ABOUT THE SERIES========>
//THE BUTTERFLY SERIES-(MAY-2020).
//SPONSERED BY QUANTUM SPACE(CEO-NAIMUL ISLAM).
//CONTROLLER=>SAFIA BEGUM(CEO-BACKS/ASH).
//ADVISOR=>NASRULLAH SAMI(CEO-FALCON AXIS).
//CO-CHIEF ADVISOR=>G.M NAYEEM(CEO-TECH FRIGATE).
//PRESIDENT=>SAMIA PREITY(CEO-FASTEX AND SPAIT).

