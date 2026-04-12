#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s[102];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int r,c;
    cin>>r>>c;
    for(int i=0; i<r; i++)
        cin>>s[i];
    for(int i=0; i<r; i++)
    {
        int cnt=0;
        for(int j=0; j<c; j++)
        {
            if(s[i][j]=='.' || s[i][j]=='X')
                cnt++;
        }
        if(cnt==c)
        {
            for(int j=0; j<c; j++)
                s[i][j]='X';
        }
    }
    for(int j=0; j<c; j++)
    {
        int cnt=0;
        for(int i=0; i<r; i++)
        {
            if(s[i][j]=='.' || s[i][j]=='X')
                cnt++;
        }
        if(cnt==r)
        {
           for(int i=0; i<r; i++)
                s[i][j]='X';
        }
    }
    vector<string>v;
    for(int i=0;i<r;i++){
        string cur="";
        for(int j=0;j<c;j++){
            if(s[i][j]!='X')
                cur+=s[i][j];
        }
        if(cur.size())
            v.push_back(cur);
    }
    for(auto i:v)
        cout<<i<<endl;

    return 0;
}
