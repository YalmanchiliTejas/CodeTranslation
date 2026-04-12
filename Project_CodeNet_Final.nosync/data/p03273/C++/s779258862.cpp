#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0;i < n;i++)
#define REPR(i,n) for(int i = n-1;i >= 0;i--)
#define FOR(i,m,n) for(int i = m;i < n;i++)
#define INF 2e9
#define ALL(v) v.begin(),v.end()
#define ll long long
#define GREATER greater<int>()

using namespace std;

string pop_back(string s){
    string t = s.substr(0,s.size()-1);
    return t;
}

int gcd(int max,int min){
    
    if(max<min){
        int tmp=max;
        max=min;
        min=tmp;
    }

    if(max%min==0)return min;
    else return gcd(min,max%min);

}

int main(void){

    int h,w;
    cin>>h>>w;
    char a[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        bool lflag=false;
       for(int j=0;j<w;j++){
            bool flag1=false,flag2=false;
            if(a[i][j]=='#'){
                flag1=true;
                flag2=true;
            }
            else{
                for(int k=0;k<h;k++){
                    if(a[k][j]=='#')flag1=true;
                }
                for(int l=0;l<w;l++){
                    if(a[i][l]=='#')flag2=true;
                }
            }
            if(flag1&flag2){
                cout<<a[i][j];
                lflag=true;
            }
        }
        if(lflag)
            cout<<endl; 
    }

    return 0;
}


