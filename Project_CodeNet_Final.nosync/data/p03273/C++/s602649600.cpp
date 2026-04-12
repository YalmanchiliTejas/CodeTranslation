#include <bits/stdc++.h>
using namespace std;

char mp[150][150];
int judx[150],judy[150];
int h,w;

int main(void)
{
    cin >>h>>w;
    
    char ch;
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            cin >>mp[i][j];
        }
    }

    for(int i=1; i<=w; i++) {
        bool flag=true;
        for(int j=1; j<=h; j++) {
            if(mp[j][i] =='#') flag=false;
        }
        if(flag) judx[i]=1;
    }

    for(int i=1; i<=h; i++) {
        bool flag=true;
        for(int j=1; j<=w; j++) {
            if(mp[i][j] =='#') flag=false;
        }
        if(flag) judy[i]=1;
    }

    for(int i=1; i<=h; i++) {
        if(judy[i]) continue;
        for(int j=1; j<=w; j++) {
            if(judx[j]) continue;
            cout <<mp[i][j];
        }
        cout <<endl;
    }

    return 0;
}