#include <bits/stdc++.h>
#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll gcd(ll a,ll b){while(a&&b)a>b?a%=b:b%=a;return a+b;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

char a[10][10];
int h, w;
bool isvisited[10][10];

bool possible(int x, int y){
    isvisited[x][y] = 1;
    if(x==h-1 && y==w-1)
        return 1;
    if(a[x][y+1]=='#')
        return possible(x,y+1);
    if(a[x+1][y]=='#')
        return possible(x+1,y);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);cout.tie(NULL);
    int i, j;
    cin>>h>>w;
    fo(i,h)
        fo(j,w)
            cin>>a[i][j];
    if(a[0][0]!='#' || a[h-1][w-1]!='#'){
        cout<<"Impossible"<<endl;
        return 0;
    }

    fo(i,10)
        fo(j,10)
            if(a[i][j]=='#')
                isvisited[i][j] = 0;
            else
                isvisited[i][j] = 1;

    int p = possible(0,0);
    if(p){
        fo(i,10)
            fo(j,10)
                if(isvisited[i][j]==0){
                    cout<<"Impossible"<<endl;
                    return 0;
                }
        cout<<"Possible"<<endl;
    }
    else
        cout<<"Impossible"<<endl;
    return 0;
}
