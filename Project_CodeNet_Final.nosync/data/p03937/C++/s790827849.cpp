#include <bits/stdc++.h>
#define  rep(i,n) for(li i=0;i<(n);i++)
#define  Rep(i,j,n) for(li i=(j);i<(n);i++)
using namespace std;
typedef long int li;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<li> vli;


int main(int argc,char* argv[])
{
    int H,W,cnt=0;
    char c;
    cin>>H>>W;
    rep(i,H*W){
        cin>>c;
        if(c=='#') cnt++;
    }
    if(cnt==H+W-1) cout<<"Possible\n";
    else cout<<"Impossible\n";


    return 0;
}