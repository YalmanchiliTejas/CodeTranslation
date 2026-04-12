#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <list>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

int i,j,k,l,m,n;
/////////////////////////////////////////////////////

int H,W;
char str[111][111];
int hc[111],wc[111];
char ref[111][111];

int main(){
    cin>>H>>W;
    for(i=0;i<H;i++){
        cin>>str[i];
    }

    for(i=0;i<H;i++)hc[i]=0;
    for(i=0;i<W;i++)wc[i]=0;

    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            if(str[i][j]=='#'){
                hc[i]=1;
                wc[j]=1;
            }
        }
    }

    for(i=0;i<H;i++){
        if(hc[i]==0)
            continue;
        for(j=0;j<W;j++){
            if(wc[j]==0)
                continue;
            cout<<str[i][j];
        }
        cout<<endl;
    }
    return 0;
}