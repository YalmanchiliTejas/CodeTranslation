#include <bits/stdc++.h>

using namespace std;
int H, W;
int field[101][101];
char tmp[101];

vector<int> xid, yid;

void compress(int H, int W){
    for(int j = 0; j< W; j++){
        for(int i=0; i<H; i++){
            if(field[i][j]){
                xid.push_back(j);
                break;
            }
        }
    }
}

int main(){
    scanf("%d%d", &H, &W);
    for(int i=0; i<H; i++){
        scanf("%s", tmp);
        for(int j=0; j<W; j++){
            if(tmp[j] == '.') field[i][j] = 0;
            else field[i][j] = 1, yid.push_back(i);
        }
    }
    yid.erase(unique(yid.begin(), yid.end()), yid.end());
    compress(H, W);
    xid.erase(unique(xid.begin(), xid.end()), xid.end());

    for(auto yit = yid.begin(); yit != yid.end(); yit++){
        for(auto xit = xid.begin(); xit != xid.end(); xit++){
            if(field[*yit][*xit]) printf("%c", '#');
            else printf("%c", '.');
        }
    printf("\n");
    }
}

