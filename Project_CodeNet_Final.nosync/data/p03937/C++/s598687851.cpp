#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int h,w;
    cin >> h >> w;
    char a[h][w];
    int count=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
            if(a[i][j]=='#')count++;
        }
    }
    if(count==h+w-1){
        puts("Possible");
        return 0;
    }
    puts("Impossible");
}