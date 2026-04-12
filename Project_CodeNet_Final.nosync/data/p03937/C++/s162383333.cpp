#include<bits/stdc++.h>
#define int long long
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef pair<int,int> PII;
static const int INF = 1ll<<60;

string s[10];

signed main(){
    int w,h;
    cin>>h>>w;
    for(int y=0;y<h;++y)cin>>s[y];
    for(int y=0;y<h;++y){
        for(int x=0;x<w;++x){
            if(s[y][x]!='#')continue;
            if(x-1>=0&&y-1>=0)if(s[y-1][x]=='#'&&s[y][x-1]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
            if(s[y+1][x]=='#'&&s[y][x+1]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;
}
