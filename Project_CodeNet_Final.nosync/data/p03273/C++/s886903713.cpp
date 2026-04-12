#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
int main() {
    int h, w; scanf("%d%d", &h, &w);
    vector <string> lines(h);
    vector <int> cols(h, 0), rows(w, 0);
    for(int i=0;i<h;i++)cin >> lines[i];
    for(int col=0;col<h;col++){
        for(int row=0;row<w;row++){
            if(lines[col][row]=='#'){cols[col]=1;rows[row]=1;}        
            }
    }
    for(int col=0;col<h;col++){
        if(cols[col]==1){
            for(int row=0;row<w;row++){
                if(rows[row]==1)printf("%c", lines[col][row]);
            }
            printf("\n");
        }
    }
    return 0;
}