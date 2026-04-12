#include <iostream>
#include <stdio.h>

using namespace std;

char str[10][10];

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s",str[i]);
    }
    int mins,maxs;
    int foo;
    for(int i=0; i<n; i++) {
        mins=10000;
        maxs=-10;
        for(int j=0; j<n; j++) {
            if(str[i][j]=='#') {
                mins=min(mins,j);
                maxs=max(j,maxs);
                /*cout<<"ns=="<<mins<<endl;
                cout<<"xs=="<<maxs<<endl;*/
            }
            /*cout<<"mins=="<<mins<<endl;
            cout<<"maxs=="<<maxs<<endl;*/
        }
        if(i!=0) {
            if(foo!=mins) {
                puts("Impossible");
                return 0;
            } else {
                foo=maxs;
            }
        } else {
            foo=maxs;
        }
    }
    puts("Possible");
    return 0;
}
