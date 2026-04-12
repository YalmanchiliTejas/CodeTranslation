#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;
#define PI acos(-1.0)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int main()
{
 
    int r, c, i, j, f;
    char s[150][150];
    cin>>r>>c;
    map <int,int> mpr, mpc;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)cin>>s[i][j];
    }
    for(i=0;i<r;i++){
        f=0;
        for(j=0;j<c;j++){
           if(s[i][j]=='#'){
                f=1;
                break;
           }
        }
        if(f==1)mpr[i]=-1;
    }
    for(i=0;i<c;i++){
        f=0;
        for(j=0;j<r;j++){
           if(s[j][i]=='#'){
                f=1;
                break;
           }
        }
        if(f==1)mpc[i]=-1;
    }
    for(i=0;i<r;i++){
        f=0;
        for(j=0;j<c;j++){
           if(mpr[i]==-1 && mpc[j]==-1){
                cout<<s[i][j];f=1;
            }
        }
        if(f)cout<<endl;
    }
    return 0;
}