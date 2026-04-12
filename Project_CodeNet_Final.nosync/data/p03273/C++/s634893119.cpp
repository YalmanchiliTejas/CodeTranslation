#include <iostream>
#include<math.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
        int H, W;
        char a[110][110];
        int couh=0,couw=0;
        int counth[110], countw[110];

        cin >> H >> W;

        for(int i=0; i<H; i++){
                for(int j=0; j<W; j++){
                        cin >> a[i][j];
                }
        }

        for(int i=0; i<H; i++){
                bool fl=true;
                for(int j=0; j<W; j++){
                        if(a[i][j]!='.') fl=false;
                }
                if(!fl){
                        counth[couh]=i;
                        couh++;
                }
        }

        for(int i=0; i<W; i++){
                bool fl=true;
                for(int j=0; j<H; j++){
                        if(a[j][i]!='.') fl=false;
                }
                if(!fl){
                        countw[couw]=i;
                        couw++;
                }
        }

        for(int i=0; i<couh; i++){
                for(int j=0; j<couw; j++){
                        cout << a[counth[i]][countw[j]];
                }
                cout <<endl;
        }
        return 0;
}
