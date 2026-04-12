#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    int h,w;cin>>h>>w;
    vector<string> a(h);
    for(int i=0;i<h;i++){
        cin>>a[i];
    }

    int numy=0,numx=0;
    while(1){
        bool cantgo=true;
        while(numx<w && numy<h && a[numy][numx]=='#'){
            a[numy][numx]='.';
            numx++;
            cantgo=false;
        }
        numx--;
        numy++;

        while(numx<w && numy<h && a[numy][numx]=='#'){
            a[numy][numx]='.';
            numy++;
            cantgo=false;
        }
        numy--;
        numx++;

        if(cantgo){break;}
    }

    bool ok=true;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#') ok=false;
        }
    }

    if(ok) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}