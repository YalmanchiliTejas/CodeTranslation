#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define eps 1e-6
#define mp make_pair
const long long INF=1e18+2;
const int MX=353;
int N, M, k;
ll arr[MX];
int row[222], col[222];
char g[MX][MX];
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            char c;
            cin>>c;
            g[i][j]=c;
            if(c == '#') row[i]++, col[j]++;
        }
    }
    vector<vector<char > > an(222);
    for(int i=0;i<N;i++)
    {
        bool p=0;
        for(int j=0;j<M;j++)
        {
           if(col[j] && row[i])cout<<g[i][j], p=1;

        }
        if(!p) continue;
        cout<<endl;
    }
    return 0;
}

