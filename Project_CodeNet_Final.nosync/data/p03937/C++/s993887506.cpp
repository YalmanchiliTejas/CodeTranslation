#include<bits/stdc++.h>
using namespace std;
char ch[10][10];

int main(){
    int h,w;
    cin>>h>>w;
    int total = 0;
    for(int i = 0; i<h; i++)
        for(int j = 0; j<w; j++){
            cin>>ch[i][j];
            if(ch[i][j]=='#')
                total++;
        }
    int i = 0, j = 0;
    bool ans = 1;
    if(ch[0][0]=='#')
        total--;
    while(1){
        if(i==h-1&&j==w-1)
            break;
        if(ans == 0)
            break;
        if( ch[i+1][j]=='#' && ch[i][j+1]=='#')
            ans = 0;
        else if(ch[i+1][j]=='#'){
            i++;
            total--;
            continue;
        }
        else if(ch[i][j+1]=='#'){
            j++;
            total--;
            continue;
        }

        else
            ans = 0;
    }

    if(total!=0)
        ans = 0;
    if(ans==0)
        cout<<"Impossible"<<endl;
    else
        cout<<"Possible"<<endl;

}
