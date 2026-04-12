#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define EPS 0.0000000001
#define INF 1000000000
#define MOD 1000000007
typedef long long ll;

int main()
{
    int h,w;
    cin>>h>>w;
    char a[h][w];
    char b[h][w];
    char c[h][w];
    int memo=0;
    int cnt;
    for(int i=0;i<h;i++){
        cnt=0;
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                cnt++;
            }
        }
        if(cnt!=w){
            //memo++;
            for(int j=0;j<w;j++){
                b[memo][j]=a[i][j];
            }
            memo++;
        }
    }
    //memo++;
    int lll=0;
    for(int j=0;j<w;j++){
        cnt=0;
        int x=0;
        for(int i=0;i<memo;i++){
            if(b[i][j]=='.'){
                x++;
            }
        }
    
        if(x!=memo){
            //lll++;
            for(int i=0;i<memo;i++){
                c[i][lll]=b[i][j];
            }
            lll++;
        }
    }
    //lll++;
    for(int i=0;i<memo;i++){
        for(int j=0;j<lll;j++){
            cout<<c[i][j];
        }
        cout<<endl;
    }

}
