#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)

int n;
int d[6] = {1,2,6,5,3,4};

void init_dice(void) {
    d[0]=1;d[1]=2;d[2]=6;d[3]=5;d[4]=3;d[5]=4;
}

/*
void printDice(void) {
    rep(i,6) {
        cout<<d[i];
        if(i==5) cout<<"\n";
        else cout<< " ";
    }
}
*/

void North(void) {
    int t1=d[0],t2=d[3];
    d[0]=d[1]; d[1]=d[2];
    d[2]=t2; d[3]=t1;
}

void South(void) {
    int t1=d[0],t2=d[1];
    d[0]=d[3]; d[3]=d[2];
    d[1]=t1; d[2]=t2;
}

void East(void) {
    int t1=d[0],t2=d[4];
    d[0]=d[5]; d[5]=d[2];
    d[2]=t2; d[4]=t1;
}

void West(void) {
    int t1=d[0],t2=d[5];
    d[0]=d[4]; d[4]=d[2];
    d[2]=t2; d[5]=t1;
}

void Left(void) {
    int t1=d[1];
    d[1]=d[5]; d[5]=d[3];
    d[3]=d[4]; d[4]=t1;
}

void Right(void) {
    int t1=d[1];
    d[1]=d[4]; d[4]=d[3];
    d[3]=d[5]; d[5]=t1;
}


int main() {
    while(cin>>n && n) {
        init_dice();
        int ans = 1;
        rep(i,n) {
            string s; cin>>s;
            if(s == "North") North();
            if(s == "South") South();
            if(s == "East") East();
            if(s == "West") West();
            if(s == "Left") Left();
            if(s == "Right") Right();
            //printDice();
            ans += d[0];
        }
        cout << ans << "\n";
    }

    
    return 0;
}