#include <iostream>
using namespace std;

int main(){
        int h, w;
        char a[8][8];

        cin>>h>>w;
        int cnt=0;
        for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                        cin>>a[i][j];
                        if(a[i][j]=='#') cnt++;
                }
        }

        int x=0,y=0;
        bool ans;
        cnt--;
        while(1){
                if(x==w-1 && y==h-1){
                        if(cnt==0) ans=true;
                        else ans=false;
                        break;
                }
                if(x+1<w && a[y][x+1]=='#') x++;
                else if(y+1<h && a[y+1][x]=='#') y++;
                else{
                        ans=false;
                        break;
                }
                cnt--;
        }

        if(ans) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;

        return 0;
}
