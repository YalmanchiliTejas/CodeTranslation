#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();
    int h, w;

    cin>> h>> w;
    char a[h+10][w+10];

    int r[h+1]= {}, c[w+1]={};


    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin>> a[i][j];

            if( a[i][j]=='#')
            {
                r[i]++;
                c[j]++;
            }
        }
    }


    for(int i=0; i<h; i++)
    {
        if(r[i]== 0)
            continue;
        for(int j=0; j<w; j++)
        {
            if(c[j]== 0)
            continue;

            cout << a[i][j];

        }
        nl;
    }




    return 0;
}


