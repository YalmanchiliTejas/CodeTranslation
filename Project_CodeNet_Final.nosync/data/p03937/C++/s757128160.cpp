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
    char a[h+1][w+1];
    char b[h+1][w+1];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            b[i][j]='.';
        }
    }
    int k=0;
    int aaa=0,bbb=0;
    for(int i=0;i<h+w+10;i++){
        if(aaa==h-1&&bbb==w-1){
            break;
        }

        if(a[aaa+1][bbb]=='#'){
            aaa++;
            b[aaa][bbb]='#';
            continue;
        }
        if(a[aaa][bbb+1]=='#'){
            bbb++;
            b[aaa][bbb]='#';
            continue;
        }
        break;
    }
    b[0][0]='#';

    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]!=b[i][j]){
                k++;
            }
        }
    }

    //cout<<k<<endl;

    if(k==0){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }

}
