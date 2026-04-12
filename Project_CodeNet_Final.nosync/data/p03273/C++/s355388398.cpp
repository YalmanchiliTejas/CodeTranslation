#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define pii pair < int , int >
#define vi vector < int >
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define init(x, a) memset(x, a, sizeof(x))
#define vll vector < long long int >
#define sll set < long long int >
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const ll mod = 1e9+7;

int main()
{
	//fastIO;
	ll h,w;
    cin>>h>>w;
    char A[h][w];
    int i,j;
    fo(i,h)
    {
        fo(j,w)
        {
            cin>>A[i][j];
        }
    }
    bool row[h],column[w];
    int count = 0;
    int newh = h, neww=w;
    fo(i,h)
    {   
        row[i]=0;
        count=0;
        fo(j,w)
        {
            if(A[i][j]=='.') count++;
        }
        if(count==w) {row[i]=1;newh--;}
    }
    fo(j,w)
    {   
        column[j]=0;
        count=0;
        fo(i,h)
        {
            if(A[i][j]=='.') count++;
        }
        if(count==h) {column[j]=1;neww--;}
    }
    char ans[newh][neww];
    bool nop = 0;
    fo(i,h)
    {   
        nop=0;
        fo(j,w)
        {
            if(column[j]!=1 and row[i]!=1) {cout<<A[i][j];}
        }
        if(row[i]!=1) cout<<'\n';
    }
    //cout<<endl;   
}