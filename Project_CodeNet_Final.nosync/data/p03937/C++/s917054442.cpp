#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mnx = 3e5 + 9;
const int mod = 1e9 + 7;

ll h, w;
char a[9][9];

int main(){

cin>>h>>w;

for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
        cin>>a[i][j];
    }
}

for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
        if(a[i+1][j] == '#' && a[i][j+1] == '#'){ cout<<"Impossible\n"; return 0; }
        if(a[i-1][j] == '#' && a[i][j-1] == '#'){ cout<<"Impossible\n"; return 0; }
    }
}

cout<<"Possible\n";

return 0;

}












